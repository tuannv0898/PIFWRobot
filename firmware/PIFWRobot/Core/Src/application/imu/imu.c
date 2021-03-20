/*
 * IMU.c
 *
 *  Created on: Oct 9, 2019
 *      Author: 16138
 */

#ifndef USERCODE_IMU_IMU_C_
#define USERCODE_IMU_IMU_C_

#include <application/imu/imu.h>
#include <application/params/params.h>
#include <application/user_define.h>
#include <math.h>

static float roll;
static float pitch;
static float motion_6[9];

TID(gtid_imu_callback);

static void imu_callback(void* ctx){
	if(mpu9250_get_accel_gyro(&motion_6[0], &motion_6[1], &motion_6[2], &motion_6[3], &motion_6[4], &motion_6[5]) < 0) return;
	if(mpu9250_get_mag(&motion_6[6], &motion_6[7], &motion_6[8]) < 0) return;

	float accel_roll  = atan2(motion_6[1], sqrt(motion_6[0]*motion_6[0] + motion_6[2]*motion_6[2]))*180.f/M_PI;
	float accel_pitch = atan2(-motion_6[0], sqrt(motion_6[1]*motion_6[1] + motion_6[2]*motion_6[2]))*180.f/M_PI;
	float roll_rate = (motion_6[3]-params.gx_offset)*0.001f*IMU_PERIOD;
	float pitch_rate = (motion_6[4]-params.gy_offset)*0.001f*IMU_PERIOD;
	roll = params.g_believe*(roll+roll_rate) + (1-params.g_believe)*accel_roll;
	pitch = params.g_believe*(pitch+pitch_rate) + (1-params.g_believe)*accel_pitch;
	if(isnan(roll)) roll = 0;
	if(isnan(pitch)) pitch = 0;
}

int imu_init(void){
	mpu9250_init();
	gtid_imu_callback = timer_register_callback(imu_callback, IMU_PERIOD, 0, TIMER_MODE_REPEAT);

	return true;
}

int imu_deinit(void){
	timer_unregister_callback(gtid_imu_callback);
	return true;
}

int imu_test_connection(){
	return mpu9250_test();
}

float imu_get_roll(void){
	return roll;
}

float imu_get_pitch(void){
	return pitch;
}

float imu_get_yaw(void){
	return 0;
}

int imu_get_accel_raw(float raw[3]){
	raw[0] = motion_6[0];
	raw[1] = motion_6[1];
	raw[2] = motion_6[2];
	return 0;
}

int imu_get_gyro_raw(float raw[3]){
	raw[0] = motion_6[3];
	raw[1] = motion_6[4];
	raw[2] = motion_6[5];
	return 0;
}

int imu_get_mag_raw(float raw[3]){
	raw[0] = motion_6[6];
	raw[1] = motion_6[7];
	raw[2] = motion_6[8];
	return 0;
}

#endif /* USERCODE_IMU_IMU_C_ */
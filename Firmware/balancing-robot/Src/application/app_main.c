/*
 * app_main.c
 *
 *  Created on: Oct 9, 2019
 *      Author: 16138
 */

#ifndef USERCODE_APP_MAIN_C_
#define USERCODE_APP_MAIN_C_

#include <application/app_main.h>

typedef void (*func_t)(void);

static func_t 		 	gmode_init;			// Save mode init function pointer
static func_t 		 	gmode_deinit;		// Save mode de-init function pointer
static on_mav_recv_t 	gon_mode_mav_recv;	// Save mode msg receive function pointer

void LED_Callback(void *context)
{
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

static void on_mavlink_recv(mavlink_message_t *msg){

	// Check if message is a change mode command. If not, send message to higher level layer
	if(msg->msgid == MAVLINK_MSG_ID_CMD_CHANGE_MODE){

		// De-initialize current mode
		gmode_deinit();

		// Parse change mode message
		mavlink_cmd_change_mode_t cmd_change_mode;
		mavlink_msg_cmd_change_mode_decode(msg, &cmd_change_mode);

		// Prepare for new mode
		if(cmd_change_mode.cmd_change_mode == MODE_RUN){
			gmode_init = mode_run_init;
			gmode_deinit = mode_run_deinit;
			gon_mode_mav_recv = on_mode_run_mavlink_recv;
		}
		else if(cmd_change_mode.cmd_change_mode == MODE_HW){
			gmode_init = mode_hw_init;
			gmode_deinit = mode_hw_deinit;
			gon_mode_mav_recv = on_mode_hw_mavlink_recv;
		}
		else if(cmd_change_mode.cmd_change_mode == MODE_IMU){
			gmode_init = mode_imu_init;
			gmode_deinit = mode_imu_deinit;
			gon_mode_mav_recv = on_mode_imu_mavlink_recv;
		}
		else if(cmd_change_mode.cmd_change_mode == MODE_PIDT_TW || cmd_change_mode.cmd_change_mode == MODE_PIDT_TA){
			gmode_init = mode_pidt_init;
			gmode_deinit = mode_pidt_deinit;
			gon_mode_mav_recv = on_mode_pidt_mavlink_recv;
		}

		// Initialize new mode
		gmode_init();

		// Response ok
		respond_ok();
	}
	else{
		gon_mode_mav_recv(msg);
	}
}

void app_main(){

	buzzer_sys_start();

	timer_init();
	timer_register_callback(LED_Callback, 500, 0, TIMER_MODE_REPEAT);

	// Load parameters from non-volatile memory
	params_load();

	// Run default mode
	gmode_init = mode_run_init;
	gmode_deinit = mode_run_deinit;
	gon_mode_mav_recv = on_mode_run_mavlink_recv;
	gmode_init();

	// Initialize communication
	mav_init();
	mav_set_on_mav_recv(on_mavlink_recv);
}

#endif /* USERCODE_APP_MAIN_C_ */
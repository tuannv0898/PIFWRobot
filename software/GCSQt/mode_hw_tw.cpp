#include "mode_hw_tw.h"
#include "ui_mode_hw_tw.h"

Mode_hw_tw::Mode_hw_tw(QWidget *parent, CommonObject *co) :
    Mode_common(parent, co),
    ui(new Ui::Mode_hw_tw)
{
    ui->setupUi(this);
    g_mode_name = "Mode hardware";
}

Mode_hw_tw::~Mode_hw_tw()
{
    delete ui;
}

void Mode_hw_tw::select(){
//   clear_drawing_area();
}


void Mode_hw_tw::mav_recv(mavlink_message_t *msg){
    switch(msg->msgid) {
    case MAVLINK_MSG_ID_RESPOND:
        {
            mavlink_respond_t respond_msg;
            mavlink_msg_respond_decode(msg,&respond_msg);
            if(respond_msg.respond == RESPOND_OK) succeed();
            else failed();
        }
        break;
    case MAVLINK_MSG_ID_HW_PARAMS:
        {
            mavlink_hw_params_t hw_params_msg;
            mavlink_msg_hw_params_decode(msg,&hw_params_msg);
            switch (hw_params_msg.motor_type) {
                case MOTOR_TYPE_DC:
                    ui->cb_motor_type->setCurrentText("DC");
                break;
                case MOTOR_TYPE_STEP:
                    ui->cb_motor_type->setCurrentText("STEP");
                break;
            }
            ui->cb_motor0_invert->setCheckState(hw_params_msg.motor0_invert == MAV_TRUE  ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
            ui->cb_motor1_invert->setCheckState(hw_params_msg.motor1_invert == MAV_TRUE  ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
            ui->cb_enc0_invert->setCheckState(hw_params_msg.encoder0_invert == MAV_TRUE  ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
            ui->cb_enc1_invert->setCheckState(hw_params_msg.encoder1_invert == MAV_TRUE  ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
            ui->cb_enc_exchange->setCheckState(hw_params_msg.encoder_exchange == MAV_TRUE  ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
            ui->txtb_motor0_pos_deadband->setText(QString::number(hw_params_msg.motor0_pos_deadband));
            ui->txtb_motor0_neg_deadband->setText(QString::number(hw_params_msg.motor0_neg_deadband));
            ui->txtb_motor1_pos_deadband->setText(QString::number(hw_params_msg.motor1_pos_deadband));
            ui->txtb_motor1_neg_deadband->setText(QString::number(hw_params_msg.motor1_neg_deadband));
            show_status("Succeed to load hardware params",2000);
            reset_timeout();
        }
        break;
    case MAVLINK_MSG_ID_MOTOR_SPEED:
        mavlink_motor_speed_t motor_speed_msg;
        mavlink_msg_motor_speed_decode(msg, &motor_speed_msg);
        ui->txtb_enc0_speed->setText(QString::number(motor_speed_msg.motor_speed_0));
        ui->txtb_enc1_speed->setText(QString::number(motor_speed_msg.motor_speed_1));
        break;
    }
}

void Mode_hw_tw::on_btn_change_mode_hw_clicked()
{
    emit mode_change(MODE_HW);
}

void Mode_hw_tw::on_btn_mode_hw_load_params_clicked()
{
    load_params();
}

void Mode_hw_tw::on_btn_mode_hw_write_params_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];

    int8_t motor0_invert = ui->cb_motor0_invert->checkState() == Qt::CheckState::Checked ? MAV_TRUE : MAV_FALSE;
    int8_t motor1_invert = ui->cb_motor1_invert->checkState() == Qt::CheckState::Checked ? MAV_TRUE : MAV_FALSE;
    int8_t encoder0_invert = ui->cb_enc0_invert->checkState() == Qt::CheckState::Checked ? MAV_TRUE : MAV_FALSE;
    int8_t encoder1_invert = ui->cb_enc1_invert->checkState() == Qt::CheckState::Checked ? MAV_TRUE : MAV_FALSE;
    int8_t encoder_ex = ui->cb_enc_exchange->checkState() == Qt::CheckState::Checked ? MAV_TRUE : MAV_FALSE;
    int16_t motor0_pos_deadband = ui->txtb_motor0_pos_deadband->text().toInt();
    int16_t motor0_neg_deadband = ui->txtb_motor0_neg_deadband->text().toInt();
    int16_t motor1_pos_deadband = ui->txtb_motor1_pos_deadband->text().toInt();
    int16_t motor1_neg_deadband = ui->txtb_motor1_neg_deadband->text().toInt();
    mavlink_msg_hw_params_pack(0,0,&msg,MOTOR_TYPE_UNKNOWN,motor0_invert,motor1_invert,encoder0_invert,encoder1_invert, encoder_ex,
                               motor0_pos_deadband, motor0_neg_deadband, motor1_pos_deadband, motor1_neg_deadband);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);

    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    show_status("Writing hardware params",1000);

    set_timeout(WRITE_TIMEOUT);
}

void Mode_hw_tw::on_btn_mode_hw_save_params_clicked()
{
    save_params();
}

void Mode_hw_tw::on_btn_set_duty0_clicked()
{
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];

    if(ui->cb_motor_type->currentText() == "DC"){
        int16_t m0 = static_cast<int16_t>(ui->txtb_motor0_duty->text().toInt());
        int16_t m1 = static_cast<int16_t>(ui->txtb_motor1_duty->text().toInt());
        mavlink_msg_motor_speed_pack(0,0,&msg,m0,m1);
    }
    else if (ui->cb_motor_type->currentText() == "STEP"){
        float m0 = ui->txtb_motor0_duty->text().toFloat();
        float m1 = ui->txtb_motor1_duty->text().toFloat();
        mavlink_msg_motor_speed_step_pack(0,0,&msg,m0,m1);
    }

    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
    show_status("Writing motor duty params",1000);
}

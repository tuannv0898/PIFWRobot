/* AUTO-GENERATED FILE.  DO NOT MODIFY.
 *
 * This class was automatically generated by the
 * java mavlink generator tool. It should not be modified by hand.
 */

// MESSAGE PID_PARAMS PACKING
package com.MAVLink.protocol;
import com.MAVLink.MAVLinkPacket;
import com.MAVLink.Messages.MAVLinkMessage;
import com.MAVLink.Messages.MAVLinkPayload;
        
/**
* PID Coefficent. No need a respond message for confimation
*/
public class msg_pid_params extends MAVLinkMessage{

    public static final int MAVLINK_MSG_ID_PID_PARAMS = 15;
    public static final int MAVLINK_MSG_LENGTH = 13;
    private static final long serialVersionUID = MAVLINK_MSG_ID_PID_PARAMS;


      
    /**
    * KP
    */
    public float KP;
      
    /**
    * KI
    */
    public float KI;
      
    /**
    * KD
    */
    public float KD;
      
    /**
    * Object that PID control
    */
    public short pid_control;
    

    /**
    * Generates the payload for a mavlink message for a message of this type
    * @return
    */
    public MAVLinkPacket pack(){
        MAVLinkPacket packet = new MAVLinkPacket(MAVLINK_MSG_LENGTH);
        packet.sysid = 255;
        packet.compid = 190;
        packet.msgid = MAVLINK_MSG_ID_PID_PARAMS;
              
        packet.payload.putFloat(KP);
              
        packet.payload.putFloat(KI);
              
        packet.payload.putFloat(KD);
              
        packet.payload.putUnsignedByte(pid_control);
        
        return packet;
    }

    /**
    * Decode a pid_params message into this class fields
    *
    * @param payload The message to decode
    */
    public void unpack(MAVLinkPayload payload) {
        payload.resetIndex();
              
        this.KP = payload.getFloat();
              
        this.KI = payload.getFloat();
              
        this.KD = payload.getFloat();
              
        this.pid_control = payload.getUnsignedByte();
        
    }

    /**
    * Constructor for a new message, just initializes the msgid
    */
    public msg_pid_params(){
        msgid = MAVLINK_MSG_ID_PID_PARAMS;
    }

    /**
    * Constructor for a new message, initializes the message with the payload
    * from a mavlink packet
    *
    */
    public msg_pid_params(MAVLinkPacket mavLinkPacket){
        this.sysid = mavLinkPacket.sysid;
        this.compid = mavLinkPacket.compid;
        this.msgid = MAVLINK_MSG_ID_PID_PARAMS;
        unpack(mavLinkPacket.payload);        
    }

            
    /**
    * Returns a string with the MSG name and data
    */
    public String toString(){
        return "MAVLINK_MSG_ID_PID_PARAMS - sysid:"+sysid+" compid:"+compid+" KP:"+KP+" KI:"+KI+" KD:"+KD+" pid_control:"+pid_control+"";
    }
}
        
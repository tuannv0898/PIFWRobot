/* AUTO-GENERATED FILE.  DO NOT MODIFY.
 *
 * This class was automatically generated by the
 * java mavlink generator tool. It should not be modified by hand.
 */

// MESSAGE EVT_RPY PACKING
package com.MAVLink.protocol;
import com.MAVLink.MAVLinkPacket;
import com.MAVLink.Messages.MAVLinkMessage;
import com.MAVLink.Messages.MAVLinkPayload;
        
/**
 * Roll pitch and yaw angle of robot in the earth frame. No need a respond message for confimation
 */
public class msg_evt_rpy extends MAVLinkMessage {

    public static final int MAVLINK_MSG_ID_EVT_RPY = 6;
    public static final int MAVLINK_MSG_LENGTH = 12;
    private static final long serialVersionUID = MAVLINK_MSG_ID_EVT_RPY;

      
    /**
     * Roll
     */
    public float roll;
      
    /**
     * Pitch
     */
    public float pitch;
      
    /**
     * Yaw
     */
    public float yaw;
    

    /**
     * Generates the payload for a mavlink message for a message of this type
     * @return
     */
    @Override
    public MAVLinkPacket pack() {
        MAVLinkPacket packet = new MAVLinkPacket(MAVLINK_MSG_LENGTH,isMavlink2);
        packet.sysid = 255;
        packet.compid = 190;
        packet.msgid = MAVLINK_MSG_ID_EVT_RPY;
        
        packet.payload.putFloat(roll);
        packet.payload.putFloat(pitch);
        packet.payload.putFloat(yaw);
        
        if (isMavlink2) {
            
        }
        return packet;
    }

    /**
     * Decode a evt_rpy message into this class fields
     *
     * @param payload The message to decode
     */
    @Override
    public void unpack(MAVLinkPayload payload) {
        payload.resetIndex();
        
        this.roll = payload.getFloat();
        this.pitch = payload.getFloat();
        this.yaw = payload.getFloat();
        
        if (isMavlink2) {
            
        }
    }

    /**
     * Constructor for a new message, just initializes the msgid
     */
    public msg_evt_rpy() {
        this.msgid = MAVLINK_MSG_ID_EVT_RPY;
    }
    
    /**
     * Constructor for a new message, initializes msgid and all payload variables
     */
    public msg_evt_rpy( float roll, float pitch, float yaw) {
        this.msgid = MAVLINK_MSG_ID_EVT_RPY;

        this.roll = roll;
        this.pitch = pitch;
        this.yaw = yaw;
        
    }
    
    /**
     * Constructor for a new message, initializes everything
     */
    public msg_evt_rpy( float roll, float pitch, float yaw, int sysid, int compid, boolean isMavlink2) {
        this.msgid = MAVLINK_MSG_ID_EVT_RPY;
        this.sysid = sysid;
        this.compid = compid;
        this.isMavlink2 = isMavlink2;

        this.roll = roll;
        this.pitch = pitch;
        this.yaw = yaw;
        
    }

    /**
     * Constructor for a new message, initializes the message with the payload
     * from a mavlink packet
     *
     */
    public msg_evt_rpy(MAVLinkPacket mavLinkPacket) {
        this.msgid = MAVLINK_MSG_ID_EVT_RPY;
        
        this.sysid = mavLinkPacket.sysid;
        this.compid = mavLinkPacket.compid;
        this.isMavlink2 = mavLinkPacket.isMavlink2;
        unpack(mavLinkPacket.payload);
    }

          
    /**
     * Returns a string with the MSG name and data
     */
    @Override
    public String toString() {
        return "MAVLINK_MSG_ID_EVT_RPY - sysid:"+sysid+" compid:"+compid+" roll:"+roll+" pitch:"+pitch+" yaw:"+yaw+"";
    }
    
    /**
     * Returns a human-readable string of the name of the message
     */
    @Override
    public String name() {
        return "MAVLINK_MSG_ID_EVT_RPY";
    }
}
        
/* AUTO-GENERATED FILE.  DO NOT MODIFY.
 *
 * This class was automatically generated by the
 * java mavlink generator tool. It should not be modified by hand.
 */

// MESSAGE CMD_PARAMS PACKING
package com.MAVLink.protocol;
import com.MAVLink.MAVLinkPacket;
import com.MAVLink.Messages.MAVLinkMessage;
import com.MAVLink.Messages.MAVLinkPayload;
        
/**
 * Save Or Load Params
 */
public class msg_cmd_params extends MAVLinkMessage {

    public static final int MAVLINK_MSG_ID_CMD_PARAMS = 2;
    public static final int MAVLINK_MSG_LENGTH = 1;
    private static final long serialVersionUID = MAVLINK_MSG_ID_CMD_PARAMS;

      
    /**
     * save or load params
     */
    public byte cmd_params;
    

    /**
     * Generates the payload for a mavlink message for a message of this type
     * @return
     */
    @Override
    public MAVLinkPacket pack() {
        MAVLinkPacket packet = new MAVLinkPacket(MAVLINK_MSG_LENGTH,isMavlink2);
        packet.sysid = 255;
        packet.compid = 190;
        packet.msgid = MAVLINK_MSG_ID_CMD_PARAMS;
        
        packet.payload.putByte(cmd_params);
        
        if (isMavlink2) {
            
        }
        return packet;
    }

    /**
     * Decode a cmd_params message into this class fields
     *
     * @param payload The message to decode
     */
    @Override
    public void unpack(MAVLinkPayload payload) {
        payload.resetIndex();
        
        this.cmd_params = payload.getByte();
        
        if (isMavlink2) {
            
        }
    }

    /**
     * Constructor for a new message, just initializes the msgid
     */
    public msg_cmd_params() {
        this.msgid = MAVLINK_MSG_ID_CMD_PARAMS;
    }
    
    /**
     * Constructor for a new message, initializes msgid and all payload variables
     */
    public msg_cmd_params( byte cmd_params) {
        this.msgid = MAVLINK_MSG_ID_CMD_PARAMS;

        this.cmd_params = cmd_params;
        
    }
    
    /**
     * Constructor for a new message, initializes everything
     */
    public msg_cmd_params( byte cmd_params, int sysid, int compid, boolean isMavlink2) {
        this.msgid = MAVLINK_MSG_ID_CMD_PARAMS;
        this.sysid = sysid;
        this.compid = compid;
        this.isMavlink2 = isMavlink2;

        this.cmd_params = cmd_params;
        
    }

    /**
     * Constructor for a new message, initializes the message with the payload
     * from a mavlink packet
     *
     */
    public msg_cmd_params(MAVLinkPacket mavLinkPacket) {
        this.msgid = MAVLINK_MSG_ID_CMD_PARAMS;
        
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
        return "MAVLINK_MSG_ID_CMD_PARAMS - sysid:"+sysid+" compid:"+compid+" cmd_params:"+cmd_params+"";
    }
    
    /**
     * Returns a human-readable string of the name of the message
     */
    @Override
    public String name() {
        return "MAVLINK_MSG_ID_CMD_PARAMS";
    }
}
        
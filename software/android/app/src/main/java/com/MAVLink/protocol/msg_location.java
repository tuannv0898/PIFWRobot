/* AUTO-GENERATED FILE.  DO NOT MODIFY.
 *
 * This class was automatically generated by the
 * java mavlink generator tool. It should not be modified by hand.
 */

// MESSAGE LOCATION PACKING
package com.MAVLink.protocol;
import com.MAVLink.MAVLinkPacket;
import com.MAVLink.Messages.MAVLinkMessage;
import com.MAVLink.Messages.MAVLinkPayload;
        
/**
 * Location message
 */
public class msg_location extends MAVLinkMessage {

    public static final int MAVLINK_MSG_ID_LOCATION = 22;
    public static final int MAVLINK_MSG_LENGTH = 14;
    private static final long serialVersionUID = MAVLINK_MSG_ID_LOCATION;

      
    /**
     * 
     */
    public float location_x;
      
    /**
     * 
     */
    public float location_y;
      
    /**
     * 
     */
    public float location_z;
      
    /**
     * 
     */
    public int uwb_address;
    

    /**
     * Generates the payload for a mavlink message for a message of this type
     * @return
     */
    @Override
    public MAVLinkPacket pack() {
        MAVLinkPacket packet = new MAVLinkPacket(MAVLINK_MSG_LENGTH,isMavlink2);
        packet.sysid = 255;
        packet.compid = 190;
        packet.msgid = MAVLINK_MSG_ID_LOCATION;
        
        packet.payload.putFloat(location_x);
        packet.payload.putFloat(location_y);
        packet.payload.putFloat(location_z);
        packet.payload.putUnsignedShort(uwb_address);
        
        if (isMavlink2) {
            
        }
        return packet;
    }

    /**
     * Decode a location message into this class fields
     *
     * @param payload The message to decode
     */
    @Override
    public void unpack(MAVLinkPayload payload) {
        payload.resetIndex();
        
        this.location_x = payload.getFloat();
        this.location_y = payload.getFloat();
        this.location_z = payload.getFloat();
        this.uwb_address = payload.getUnsignedShort();
        
        if (isMavlink2) {
            
        }
    }

    /**
     * Constructor for a new message, just initializes the msgid
     */
    public msg_location() {
        this.msgid = MAVLINK_MSG_ID_LOCATION;
    }
    
    /**
     * Constructor for a new message, initializes msgid and all payload variables
     */
    public msg_location( float location_x, float location_y, float location_z, int uwb_address) {
        this.msgid = MAVLINK_MSG_ID_LOCATION;

        this.location_x = location_x;
        this.location_y = location_y;
        this.location_z = location_z;
        this.uwb_address = uwb_address;
        
    }
    
    /**
     * Constructor for a new message, initializes everything
     */
    public msg_location( float location_x, float location_y, float location_z, int uwb_address, int sysid, int compid, boolean isMavlink2) {
        this.msgid = MAVLINK_MSG_ID_LOCATION;
        this.sysid = sysid;
        this.compid = compid;
        this.isMavlink2 = isMavlink2;

        this.location_x = location_x;
        this.location_y = location_y;
        this.location_z = location_z;
        this.uwb_address = uwb_address;
        
    }

    /**
     * Constructor for a new message, initializes the message with the payload
     * from a mavlink packet
     *
     */
    public msg_location(MAVLinkPacket mavLinkPacket) {
        this.msgid = MAVLINK_MSG_ID_LOCATION;
        
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
        return "MAVLINK_MSG_ID_LOCATION - sysid:"+sysid+" compid:"+compid+" location_x:"+location_x+" location_y:"+location_y+" location_z:"+location_z+" uwb_address:"+uwb_address+"";
    }
    
    /**
     * Returns a human-readable string of the name of the message
     */
    @Override
    public String name() {
        return "MAVLINK_MSG_ID_LOCATION";
    }
}
        
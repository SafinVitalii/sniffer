#ifndef PROTOCOLHEADERS_H
#define PROTOCOLHEADERS_H
typedef struct
{
  unsigned char  ipheaderlength : 4; // 4-bit header length (in 32-bit words)
  unsigned char  ipversion : 4;      // 4-bit IPv4 version
  unsigned char  iptype;             // IP type of service
  unsigned short iptotallength;      // Total length
  unsigned short ipid;               // Unique identifier
  unsigned char  ipfragmentoffset : 5;// Fragment offset field
  unsigned char  ipmorefragment : 1; // If this fragment is last
  unsigned char  ipdontfragment : 1; // Can't be divided
  unsigned char  ipreservedzero : 1; // Reserved
  unsigned char  ipfragmentoffset1;  //Fragment offset
  unsigned char  iptime;             // Time to live
  unsigned char  ipprotocol;         // Protocol(TCP,UDP etc)
  unsigned short ipchecksum;         // IP checksum
  unsigned int   ipsourceaddress;    // Source address
  unsigned int   ipdestinationaddress;// Destination address
} IPv4Header;

typedef struct
{
  unsigned short sourceport;         // Source port no.
  unsigned short destinationport;    // Dest. port no.
  unsigned short udppacketlength;    // Udp packet length
  unsigned short udpchecksum;        // Udp checksum
} UDPHeader;

typedef struct
{
  unsigned short sourceport;         // source port
  unsigned short destinationport;    // destination port
  unsigned int   sequence;           // sequence number - 32 bits
  unsigned int   acknowledge;        // acknowledgement number - 32 bits
  unsigned char  noncesum     : 1;   //Nonce Sum Flag Added in RFC 3540.
  unsigned char  reservedpart : 3;   //according to rfc
  unsigned char  dataoffset   : 4;   //number of dwords in the TCP header.
  unsigned char  finish       : 1;   //Finish Flag
  unsigned char  sync         : 1;   //Synchronise Flag
  unsigned char  reset        : 1;   //Reset Flag
  unsigned char  push         : 1;   //Push Flag
  unsigned char  acknowledgement : 1;//Acknowledgement Flag
  unsigned char  urgent       : 1;   //Urgent Flag
  unsigned char  ecnecho      : 1;   //ECN-Echo Flag
  unsigned char  cwr          : 1;   //Congestion Window Reduced Flag
  unsigned short window;             // window
  unsigned short checksum;           // checksum
  unsigned short urgentppointer;     // urgent pointer
} TCPHeader;
#endif // ! PROTOCOLHEADERS_H

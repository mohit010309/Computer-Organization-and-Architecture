//: version "2.1"
//: property encoding = "utf-8"
//: property locale = "en"
//: property prefix = "_GG"
//: property timingViolationMode = 2
//: property initTime = "0 ns"

`timescale 1ns/1ns

//: /netlistBegin main
module main;    //: root_module
reg [3:0] w0;    //: /sn:0 {0}(#:154,126)(154,242){1}
//: {2}(154,243)(154,279){3}
//: {4}(154,280)(154,337){5}
//: {6}(154,338)(154,386){7}
//: {8}(154,387)(154,484){9}
wire w4;    //: /sn:0 {0}(158,387)(689,387)(689,209){1}
wire w3;    //: /sn:0 {0}(158,338)(611,338)(611,203){1}
wire w1;    //: /sn:0 {0}(158,243)(431,243)(431,203){1}
wire w2;    //: /sn:0 {0}(158,280)(525,280)(525,209){1}
//: enddecls

  assign w4 = w0[0]; //: TAP g8 @(152,387) /sn:0 /R:2 /w:[ 0 8 7 ] /ss:1
  //: LED L3 (w1) @(431,196) /w:[ 1 ] /type:0
  assign w2 = w0[2]; //: TAP g6 @(152,280) /sn:0 /R:2 /w:[ 0 4 3 ] /ss:1
  //: LED L2 (w2) @(525,202) /w:[ 1 ] /type:0
  //: frame g9 @(36,60) /sn:0 /wi:786 /ht:446 /tx:"Multiple Bits"
  assign w3 = w0[1]; //: TAP g7 @(152,338) /sn:0 /R:2 /w:[ 0 6 5 ] /ss:1
  assign w1 = w0[3]; //: TAP D3 @(152,243) /sn:0 /R:2 /w:[ 0 2 1 ] /ss:1
  //: LED L0 (w4) @(689,202) /w:[ 1 ] /type:0
  //: DIP g0 (w0) @(154,116) /sn:0 /w:[ 0 ] /st:5 /dn:1
  //: LED L1 (w3) @(611,196) /w:[ 1 ] /type:0

endmodule
//: /netlistEnd


//: version "2.1"
//: property encoding = "utf-8"
//: property locale = "en"
//: property prefix = "_GG"
//: property timingViolationMode = 2
//: property initTime = "0 ns"

`timescale 1ns/1ns

//: /netlistBegin main
module main;    //: root_module
reg b;    //: {0}(23:122,304)(242,304){1}
//: {2}(244,302)(244,199)(314,199){3}
//: {4}(244,306)(244,386)(304,386){5}
reg cin;    //: {0}(466,282)(466,225){1}
//: {2}(468,223)(513,223)(513,202)(588,202){3}
//: {4}(466,221)(93:466,100)(130,100){5}
reg a;    //: {0}(314,194)(256,194){1}
//: {2}(79:252,194)(126,194){3}
//: {4}(254,196)(254,381)(304,381){5}
wire w3;    //: /sn:0 {0}(588,197)(463,197){1}
//: {2}(459,197)(335,197){3}
//: {4}(461,199)(461,282){5}
wire w8;    //: /sn:0 {0}(580,384)(325,384){1}
wire w11;    //: /sn:0 {0}(463,303)(463,379)(580,379){1}
wire cout;    //: {0}(741,350)(-43:741,382)(601,382){1}
wire s;    //: {0}(60:609,200)(736,200)(736,227){1}
//: enddecls

  //: LED g8 (s) @(736,234) /sn:0 /R:2 /w:[ 1 ] /type:0
  _GGAND2 #(6) g4 (.I0(a), .I1(b), .Z(w8));   //: @(315,384) /sn:0 /w:[ 5 5 1 ]
  _GGXOR2 #(8) g3 (.I0(a), .I1(b), .Z(w3));   //: @(325,197) /sn:0 /w:[ 0 3 3 ]
  //: SWITCH g2 (b) @(105,304) /sn:0 /w:[ 0 ] /st:1 /dn:1
  //: SWITCH g1 (a) @(109,194) /sn:0 /w:[ 3 ] /st:1 /dn:1
  //: joint g10 (a) @(254, 194) /w:[ 1 -1 2 4 ]
  _GGXOR2 #(8) g6 (.I0(w3), .I1(cin), .Z(s));   //: @(599,200) /sn:0 /w:[ 0 3 0 ]
  //: LED g9 (cout) @(741,343) /sn:0 /w:[ 0 ] /type:0
  _GGOR2 #(6) g7 (.I0(w11), .I1(w8), .Z(cout));   //: @(591,382) /sn:0 /w:[ 1 0 1 ]
  //: joint g12 (w3) @(461, 197) /w:[ 1 -1 2 4 ]
  //: frame g14 @(40,43) /sn:0 /wi:808 /ht:403 /tx:"Full Adder"
  //: joint g11 (b) @(244, 304) /w:[ -1 2 1 4 ]
  _GGAND2 #(6) g5 (.I0(cin), .I1(w3), .Z(w11));   //: @(463,293) /sn:0 /R:3 /w:[ 0 5 0 ]
  //: SWITCH g0 (cin) @(113,100) /sn:0 /w:[ 5 ] /st:1 /dn:1
  //: joint g13 (cin) @(466, 223) /w:[ 2 4 -1 1 ]

endmodule
//: /netlistEnd


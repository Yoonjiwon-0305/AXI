//Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2020.2 (win64) Build 3064766 Wed Nov 18 09:12:45 MST 2020
//Date        : Wed May  6 20:44:21 2026
//Host        : DESKTOP-7CFQ9ND running 64-bit major release  (build 9200)
//Command     : generate_target design_1_wrapper.bd
//Design      : design_1_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module design_1_wrapper
   (btn,
    cs_n,
    fnd,
    fnd_digit,
    led,
    miso,
    mosi,
    reset,
    sclk,
    sw,
    sys_clock,
    usb_uart_rxd,
    usb_uart_txd);
  inout [7:0]btn;
  output cs_n;
  inout [7:0]fnd;
  inout [7:0]fnd_digit;
  inout [7:0]led;
  input miso;
  output mosi;
  input reset;
  output sclk;
  inout [7:0]sw;
  input sys_clock;
  input usb_uart_rxd;
  output usb_uart_txd;

  wire [7:0]btn;
  wire cs_n;
  wire [7:0]fnd;
  wire [7:0]fnd_digit;
  wire [7:0]led;
  wire miso;
  wire mosi;
  wire reset;
  wire sclk;
  wire [7:0]sw;
  wire sys_clock;
  wire usb_uart_rxd;
  wire usb_uart_txd;

  design_1 design_1_i
       (.btn(btn),
        .cs_n(cs_n),
        .fnd(fnd),
        .fnd_digit(fnd_digit),
        .led(led),
        .miso(miso),
        .mosi(mosi),
        .reset(reset),
        .sclk(sclk),
        .sw(sw),
        .sys_clock(sys_clock),
        .usb_uart_rxd(usb_uart_rxd),
        .usb_uart_txd(usb_uart_txd));
endmodule

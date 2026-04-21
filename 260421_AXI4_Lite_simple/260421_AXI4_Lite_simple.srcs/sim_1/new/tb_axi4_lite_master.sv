`timescale 1ns / 1ps

module tb_axi4_lite_master ();

    logic        ACLK;
    logic        ARESETn;
    //AW 
    logic [31:0] AWADDR;
    logic        AWVALID;
    logic        AWREADY;
    //W
    logic [31:0] WDATA;
    logic        WVALID;
    logic        WREADY;
    //B
    logic [ 1:0] BRESP;
    logic        BVALID;
    logic        BREADY;
    //AR
    logic [31:0] ARADDR;
    logic        ARVALID;
    logic        ARREADY;
    //AR
    logic [31:0] RDATA;
    logic        RVALID;
    logic        RREADY;
    logic [ 1:0] RRESP;
    //Internal
    logic        transfer;
    logic        ready;
    logic [31:0] addr;
    logic [31:0] wdata;
    logic        write;
    logic [31:0] rdat;

    axi4_lite_master dut (.*);

    
endmodule

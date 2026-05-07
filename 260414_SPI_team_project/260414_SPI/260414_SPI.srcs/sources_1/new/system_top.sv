`timescale 1ns / 1ps

module system_top (
    input  logic       clk,
    input  logic       reset,
    // SPI ??
    input  logic       sclk,
    input  logic       mosi,
    output logic       miso,
    input  logic       cs_n,
    // ?��출력
    input  logic [7:0] sw,
    output logic [7:0] led
);

    logic [7:0] rx_data;
    logic [7:0] tx_data;
    logic       done;
    logic       busy;

    // tx_data = sw �? (Master?���? 보낼 ?��?��?��)
    assign tx_data = sw;

    spi_slave U_SPI_SLAVE (
        .clk     (clk),
        .reset   (reset),
        .sclk    (sclk),
        .cs_n    (cs_n),
        .tx_data (tx_data),
        .mosi    (mosi),
        .miso    (miso),
        .rx_data (rx_data),
        .done    (done),
        .busy    (busy)
    );

    // rx_data ?�� LED
    always_ff @(posedge clk or posedge reset) begin
        if (reset)    led <= 8'h00;
        else if (done) led <= rx_data;
    end

endmodule


`timescale 1ns / 1ps

module tb_spi;

    logic       clk;
    logic       reset;
    // Master 신호
    logic       sclk;
    logic       mosi;
    logic       miso;
    logic       cs_n;
    logic [7:0] m_tx_data;
    logic       start;
    logic [7:0] m_rx_data;
    logic       m_done;
    logic       m_busy;
    // Slave 신호
    logic [7:0] s_tx_data;
    logic [7:0] s_rx_data;
    logic       s_done;
    logic       s_busy;

    // clk 생성
    initial clk = 0;
    always #5 clk = ~clk;  // 100MHz

    spi_master U_MASTER (
        .clk    (clk),
        .reset  (reset),
        .cpol   (1'b0),
        .cpha   (1'b0),
        .clk_div(16'd4),
        .tx_data(m_tx_data),
        .start  (start),
        .rx_data(m_rx_data),
        .done   (m_done),
        .busy   (m_busy),
        .sclk   (sclk),
        .mosi   (mosi),
        .miso   (miso),
        .cs_n   (cs_n)
    );

    spi_slave U_SLAVE (
        .clk     (clk),
        .reset   (reset),
        .sclk    (sclk),
        .cs_n    (cs_n),
        .tx_data (s_tx_data),
        .mosi    (mosi),
        .miso    (miso),
        .rx_data (s_rx_data),
        .done    (s_done),
        .busy    (s_busy)
    );

    initial begin
        reset     = 1;
        start     = 0;
        m_tx_data = 8'hA5;  // Master → Slave: 0xA5
        s_tx_data = 8'h3C;  // Slave  → Master: 0x3C
        #20;
        reset = 0;
        #20;

        // 전송 시작
        start = 1;
        #10;
        start = 0;

        // 완료 대기
        wait(m_done);
        #10;

        $display("Master sent:     0x%02X", m_tx_data);
        $display("Slave received:  0x%02X", s_rx_data);
        $display("Slave sent:      0x%02X", s_tx_data);
        $display("Master received: 0x%02X", m_rx_data);

        #100;
        $finish;
    end

    initial begin
        $dumpfile("tb_spi.vcd");
        $dumpvars(0, tb_spi);
    end

endmodule

### __RF COMMINICATION USING CC1120 WITH MSP430FR2476__

#### __RF Communications Specifications__

* Address Config = No address check

*  Bit Rate = 19.6

* Carrier Frequency = 868.000000

*  Deviation = 10.009766

*  Device Address = 0

*  Manchester Enable = false

*  Modulation Format = 2-GFSK

*  PA Ramping = true

*  Packet Bit Length = 0

*  Packet Length = 25

*  Packet Length Mode = Fixed

*  Performance Mode = High Performance

*  RX Filter BW = 50.000000

*  Symbol rate = 19.6

*  TX Power = 15

*  Whitening = true


#### __SOFTWARE & HARDWARE__

- This tutorial was based on below reference design documents. 
[Referans Design](blob:https://www.ti.com/25310c47-8998-4fcf-ace0-8f872ff94ba0)

-  Using PCB pins are different from design , GPIO is defined in periph_init.h.

- CC1120 registers settings are in CC112X.c source file.

- The tutorial runs TX mode in every 450ms time periodes and RX mode in every 1s time periodes.

- You can look at the documents [TI Source Code](https://www.ti.com/lit/sw/swrc253e/swrc253e.zip?ts=1638169235282)

### __User's Guide__

[CC112x User's Guide](https://www.ti.com/lit/ug/swru295e/swru295e.pdf?ts=1637526707767&ref_url=https%253A%252F%252Fwww.google.com%252F)

### __ErrataSheet__
You should look at errata for chip frequency calibration.

[CC112x Errata](https://www.ti.com/lit/er/swrz039d/swrz039d.pdf?ts=1637235604593&ref_url=https%253A%252F%252Fwww.google.com%252F)



**## __IMPORTANT NOTES__**

**Please sure that defining the folder path is correct  in CSS project creation and include options**

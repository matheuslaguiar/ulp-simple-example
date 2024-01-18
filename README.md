| Supported Targets | ESP32-S2 | ESP32-S3 |
| ----------------- | -------- | -------- |
# _ESP32 ULP RISC-V Coprocessor C Programming example_

This project shows a simple example of use of the ULP RISC-V Coprocessor, present on ESP32-S2 and ESP32-S3.

Project architeture:

├── CMakeLists.txt\
├── main\
│&ensp;&ensp;├── CMakeLists.txt\
│&ensp;&ensp;└── main.c\
└── components\
&ensp;&ensp;&ensp;└── app\
&ensp;&ensp;&ensp;&ensp;&ensp;├── include\
&ensp;&ensp;&ensp;&ensp;&ensp;│&ensp;&ensp;└── app.h\
&ensp;&ensp;&ensp;&ensp;&ensp;├── ulp\
&ensp;&ensp;&ensp;&ensp;&ensp;│&ensp;&ensp;├── ulp_app.c\
&ensp;&ensp;&ensp;&ensp;&ensp;│&ensp;&ensp;└── ulp_app.h\
&ensp;&ensp;&ensp;&ensp;&ensp;├── app.c\
&ensp;&ensp;&ensp;&ensp;&ensp;└── CMakeLists.txt

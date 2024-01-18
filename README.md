| Supported Targets | ESP32-S2 | ESP32-S3 |
| ----------------- | -------- | -------- |
# _ESP32 ULP RISC-V Coprocessor C Programming example_

This project shows a simple example of use of the ULP RISC-V Coprocessor, present on ESP32-S2 and ESP32-S3.

Project architeture:
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── components
      └── app
            ├── include
            │    └── app.h
            ├── ulp
            │    ├── ulp_app.c
            │    └── ulp_app.h
            ├── app.c
            └── CMakeLists.txt
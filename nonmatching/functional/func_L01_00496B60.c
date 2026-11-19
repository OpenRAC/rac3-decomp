/* functional: high. Compiles at level_01 (32 diff). a1 is the Q_496B00 pointer the matched caller func_L01_00496B00 passes; forwarded as an s32 to func_L01_00497AC8. */
extern f32 D_L01_001D91D0;
extern f32 D_L01_001D91C8;
extern f32 D_L01_001D91CC;

extern void func_L01_004980C0(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);
extern void func_L01_00496C88();

void func_L01_00496B60(s32 a0, Q_496B00 *a1) {
    s32 str;

    func_L01_004980C0(0xD, 0x470001, 0x470002, 0x470003, 0x470004, 0x470005, 0x470006, 0x470007,
                      D_L01_001D91D0, 0xD0008, 0, 0x470008, 0x470009);
    str = func_00381FF0(0xC96);
    func_003E8FE8(0x47000A, str, 0x8066CCFF, 0.5f, 0.93f, 1.0f, 1.0f);
    func_L01_00516AA0(0x47000A, 0x40, 1);
    func_003E8630(0x470001, 0x47000A);
    func_L01_00497AC8((void *)func_L01_00496C88, a0, (s32)a1, 1, 1, 1, D_L01_001D91C8, D_L01_001D91CC);
}

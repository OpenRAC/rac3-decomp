/* functional: medium. Written from asm; table meanings unknown (naming left to the lead); i is always 0 in retail but used in the same index terms; structure matches the asm closely (116 words differ in register numbering only); raw offsets via byte arrays */
extern u8 D_002ED730[];
extern s32 D_001E0CD0[];
extern u8 D_00143950[];
extern u8 D_00143A10[];
extern u8 D_00143A70[];
extern u8 D_00143AD0[];
extern u8 D_001A71C4[];
extern s32 D_001D9570_sda;
__asm__(".extern D_001D9570_sda, 4");
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern void func_003A5348(s32, s32, s32);
extern void func_L01_004A0300(void);

void func_L01_0049FBC8(void) {
    s32 i = 0;
    s32 sel;
    s32 m;
    s32 *row;
    u8 *r;

    sel = func_003B9C58(func_003B9BD0(0));
    func_003A5348(3, 0, 0);
    if (!(D_001A71C4[0] == 1 && sel == 0) && sel != 3) {
        row = (s32 *)(D_002ED730 + sel * 0x30);
        row[0] = row[0] + 1;
        if (row[2] < row[0]) {
            row[0] = row[1];
        }
    }
    switch (*(s32 *)(D_002ED730 + i * 12)) {
    case 0:
        D_001E0CD0[i] = 0;
        break;
    case 1:
        D_001E0CD0[i] = 2;
        break;
    case 2:
        D_001E0CD0[i] = 1;
        break;
    }
    if (sel == 0) {
        func_L01_004A0300();
    }
    m = D_001E0CD0[i];
    r = D_002ED730 + i * 12;
    *(s32 *)(D_00143950 + 0x14 + m * 16 + i * 4) = *(s32 *)(r + 0x30);
    *(s32 *)(D_00143950 + 0x44 + m * 16 + i * 4) = *(s32 *)(r + 0x60);
    D_00143950[D_001D9570_sda + 0xAE] = r[0xC0];
    D_00143950[0xB6] = r[0xF0];
    *(s32 *)(D_00143A10 + m * 32) = *(s32 *)(D_00143950 + 0x14 + m * 16 + i * 4);
    *(s32 *)(D_00143A70 + m * 32) = *(s32 *)(D_00143950 + 0x44 + m * 16 + i * 4);
    *(s32 *)(D_00143AD0 + m * 32) = *(s32 *)(D_00143950 + 0x74 + m * 16 + i * 4);
}

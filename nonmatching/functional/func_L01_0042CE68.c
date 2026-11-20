/* functional: high. Prior near-miss draft checked against the PAL asm line by line (offsets, widths, call order, callee names func_003A0760/func_00399D68 = L01 36F60/427110); 23 of ~170 words differ (address-add order, scheduling). */
typedef struct {
    s32 id;
    u8 pad[16];
} E_42A520;
typedef struct {
    u8 pad[17808];
    E_42A520 e[48];
} T_160C40;
extern T_160C40 D_00160C40;
typedef struct { u8 pad[0x4594]; s32 sector; } Record_0042CE68;
typedef struct {
    s32 off0, size0, off1, size1;
} Entry_0042CE68;
typedef struct {
    s32 f0;
    u8 pad4[6];
    u16 fA;
    u8 padC[4];
    s16 f10, f12;
} State_0042CE68;
typedef struct {
    u8 pad[0x20];
    s32 f20;
    u8 pad24[0x10];
    s32 f34;
} Image_0042CE68;
typedef struct {
    u8 pad0[0xD];
    u8 count;
    u8 padE[0x1A];
    u8 *items;
} Object_0042CE68;
extern State_0042CE68 D_0016C690;
extern u32 D_00191ED0[];
extern Image_0042CE68 D_001A1ED0;
extern s32 D_00191EE8[];
extern u8 D_00191F00[];
extern u8 D_00192300[];
/* one variable, read and written at the same address in every level (retail forms the address two ways) */
extern s32 D_L01_001E0000;
extern u8 D_L01_001FDBD0[];
extern Object_0042CE68 *D_L01_001FD180[];
extern s32 D_L01_00200670[];
void func_L01_0042CE68(s32 arg0, s32 index, Entry_0042CE68 *entry) {
    extern void func_0011F0A0(s32);
    extern void func_003A0760(void *, void *);
    extern void func_0012C9A0(void *, s16, s16, s16, s16, s16, s16, s16);
    extern void func_0012CCC8(void *, void *);
    extern void func_0012A9F0(s32, s32);
    extern void func_00399D68(void *, void *, void *, s32);
    u8 buffer[0x60];
    u8 *data0;
    u8 *data1;
    s32 saved;
    Object_0042CE68 *obj;
    s32 i;
    s32 width;
    u8 *pixels;
    if (entry->size1) {
        data1 = (u8 *)entry + entry->off1;
        data1 -= (((Record_0042CE68 *)((u8 *)&D_00160C40 + index * 20))->sector << 11);
        func_0011F0A0(0);
        func_003A0760(data1, D_00191ED0);
        func_0011F0A0(0);
        if (D_00191ED0[0] == 1) {
            func_0012C9A0(buffer, D_0016C690.fA + (D_001A1ED0.f20 >> 8), 1, 0, 0, 0, 16, 16);
            func_0011F0A0(0);
            func_0012CCC8(buffer, D_00191F00);
            func_0012A9F0(0, 0);
            width = D_00191EE8[0];
            pixels = D_00192300;
            func_0012C9A0(buffer, (D_001A1ED0.f34 + D_0016C690.f0 * 4) >> 8,
                (width >> 6) > 0 ? (width >> 6) : 1, 27, 0, 0, width, width);
            func_0011F0A0(0);
            func_0012CCC8(buffer, pixels);
            func_0012A9F0(0, 0);
        }
    }
    data0 = (u8 *)entry + entry->off0;
    data0 -= (((Record_0042CE68 *)((u8 *)&D_00160C40 + index * 20))->sector << 11);
    func_0011F0A0(0);
    func_003A0760(data0, D_00191ED0);
    func_0011F0A0(0);
    buffer[0] = (u8)D_0016C690.f10;
    saved = D_L01_001E0000;
    D_L01_001E0000 = D_0016C690.f12;
    func_00399D68(D_00191ED0, (u8 *)&D_0016C690 - D_0016C690.f10 * 16, buffer, arg0);
    obj = D_L01_001FD180[D_L01_001FDBD0[arg0]];
    D_L01_00200670[D_0016C690.f12] = 0xFFF00000;
    D_L01_001E0000 = saved;
    for (i = 0; i < obj->count; i++)
        *(s32 *)(obj->items + i * 32 + 0x1C) = 4;
}

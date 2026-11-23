/* functional: medium. Renderer-state driver but game-side; callee names func_003xxxxx guessed as frontbin core fns without prototypes (args read from asm); lq/sq quad copies written as word copies; sq $0 as four zero stores; not byte checked */
typedef struct { s32 a0; s32 id; s32 mode; s32 text; } Row_0049B088;
extern Row_0049B088 D_L01_002EBDE8[];
extern u8 D_001426E0[];
extern u8 D_L01_001E7580[];
extern u8 D_L01_001E29E0[];
extern u8 D_L01_001E2A40[];
extern f32 D_L01_001D93FC;
extern f32 D_L01_001D93F4;
extern f32 D_L01_001DC0EC;
extern f32 D_L01_001DC0E8;
extern u8 *D_001D9340_sda[1];
__asm__(".extern D_001D9340_sda, 4");
extern s32 D_001D9380_sda;
__asm__(".extern D_001D9380_sda, 4");
extern s32 D_001D9384_sda;
__asm__(".extern D_001D9384_sda, 4");
extern s32 D_001D93B0_sda[4];
__asm__(".extern D_001D93B0_sda, 16");
extern s32 D_001D9390_sda[4];
__asm__(".extern D_001D9390_sda, 4");
extern s32 D_001D93A0_sda[4];
__asm__(".extern D_001D93A0_sda, 16");
extern f32 D_001D93C8_sda;
__asm__(".extern D_001D93C8_sda, 4");
extern f32 D_001D93CC_sda;
__asm__(".extern D_001D93CC_sda, 4");
extern s32 D_001DFB94_sda;
__asm__(".extern D_001DFB94_sda, 4");
extern void func_L01_0047E520(void);
extern void func_00392868(s32, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_003C25D8(u8 *, s32);
extern void func_003C6F90(u8 *, s32, s32, s32, s32);
extern void func_003C7C38(u8 *);
extern void func_0038D308(u8 *, void *);
extern void func_00387218(void);
extern void func_0038CC88(void *, void *, s32);
extern void func_003861F0(void);
extern void func_003873C0(void);
extern void func_003C36C0(void);
extern void func_003C3638(void);
extern void func_003C3660(void);
extern void func_003C2DC0(void);
extern void func_00387F68(void);
extern void func_003A9500(s32, s32, s32, s32);
extern void func_003C6FE0(u8 *);
extern void func_003C3780(u8 *, s32);
extern void func_003C3690(void);
extern void func_003C3800(void);
extern void func_003A9C70(s32);
extern void func_003A92F0(s32);
extern void func_003C31B0(void);
#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define W32(p, o) (*(s32 *)((u8 *)(p) + (o)))
void func_L01_0049B088(void) {
    f32 half, saved, f5;
    s32 lo, hi, i;
    u8 *obj;
    func_L01_0047E520();
    half = D_L01_001D93FC * 0.5f;
    f5 = D_L01_001DC0EC;
    saved = F32(D_L01_001E7580, 0xB0);
    hi = (s32)(f5 * (D_L01_001D93F4 + half) - 3.0f);
    lo = (s32)(f5 * (D_L01_001D93F4 - half) + 2.0f);
    if (D_001D9384_sda >= 0) {
        if (D_001426E0[D_L01_002EBDE8[D_001D9384_sda].id] != 0) {
            func_00392868((s32)D_L01_001DC0E8, (s32)f5);
            if (D_001D9340_sda[D_001D9384_sda] == 0) {
                obj = func_003C24B0(D_L01_002EBDE8[D_001D9384_sda].a0, 0);
                if (obj != 0) {
                    func_003C25D8(obj, D_L01_002EBDE8[D_001D9384_sda].a0);
                    *(u16 *)(obj + 0x32) = 0xC0;
                    func_003C6F90(obj, 0x5669E, 0, 0, 0);
                    W32(obj, 0x10) = D_001D93B0_sda[0];
                    W32(obj, 0x14) = D_001D93B0_sda[1];
                    W32(obj, 0x18) = D_001D93B0_sda[2];
                    W32(obj, 0x1C) = D_001D93B0_sda[3];
                }
                D_001D9340_sda[D_001D9384_sda] = obj;
            }
            if (D_001D9380_sda != D_001D9384_sda) {
                obj = D_001D9340_sda[D_001D9384_sda];
                if (obj != 0) {
                    if (D_L01_002EBDE8[D_001D9384_sda].mode == 0) {
                        W32(obj, 0xF0) = 0; W32(obj, 0xF4) = 0; W32(obj, 0xF8) = 0; W32(obj, 0xFC) = 0;
                        F32(obj, 0xF0) = 3.1415927f;
                        F32(obj, 0xF4) = 1.5707964f;
                        F32(obj, 0x2C) = F32(*(u8 **)(obj + 0x24), 0x24) * D_001D93C8_sda;
                    } else {
                        W32(obj, 0xF0) = 0; W32(obj, 0xF4) = 0; W32(obj, 0xF8) = 0; W32(obj, 0xFC) = 0;
                        F32(obj, 0x2C) = F32(*(u8 **)(obj + 0x24), 0x24) * D_001D93CC_sda * D_001D93C8_sda;
                    }
                    func_003C7C38(obj);
                    D_001D9380_sda = D_001D9384_sda;
                }
            }
            func_0038D308(D_L01_001E29E0, D_001D9390_sda);
            D_001DFB94_sda = 0;
            func_00387218();
            for (i = 0; i < 8; i++) {
                W32(D_L01_001E2A40, i * 4) = W32(D_L01_001E29E0, i * 4 - 0x20);
            }
            func_0038CC88(D_L01_001E2A40 + 0x380, D_L01_001E29E0, 0x30);
            func_003861F0();
            F32(D_L01_001E7580, 0xB0) = 0.62f;
            func_003873C0();
            func_003C36C0();
            func_003C3638();
            func_003C3660();
            for (i = 0; i < 4; i++) {
                W32(D_L01_001E29E0, i * 4 - 0x20) = D_001D93A0_sda[i];
            }
            func_003861F0();
            func_003C2DC0();
            func_00387F68();
            func_003A9500(0, (s32)D_L01_001DC0E8, lo, hi);
            func_003C6FE0(D_001D9340_sda[D_001D9384_sda]);
            func_003C7C38(D_001D9340_sda[D_001D9384_sda]);
            func_003C3780(D_001D9340_sda[D_001D9384_sda], 1);
            func_003C3690();
            func_003C3800();
            func_003A9C70(0x2080000);
            func_003A9500(0, (s32)D_L01_001DC0E8 - 1, 0, (s32)D_L01_001DC0EC - 1);
            func_003A92F0(0x10);
            func_003C31B0();
            F32(D_L01_001E7580, 0xB0) = saved;
            func_003873C0();
        }
    }
}

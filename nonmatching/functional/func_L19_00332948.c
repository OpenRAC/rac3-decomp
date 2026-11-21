/* functional: medium. Per-frame update of a Thran level pickup/enemy object (not hand-asm): runs state-0 init, copies flags from its definition, near-camera triggers, hit test, spawns an effect and kills itself when hit, bumps debug counters, then calls the shared update. Control flow re-read block by block against asm; dead branch (b20 != 1 after b20 >= 2) kept. Only instruction scheduling differs per check.py. */
extern s32 D_L19_001DF240;
extern s32 D_001DCBD4_sda, D_001DCBD8_sda;
extern u8 D_001E2100[];
extern u8 D_1A4C60[];
extern u16 D_001DF42C[], D_001DF42E[], D_001DF430[], D_001DF432[], D_001DF434[];
extern void func_L19_00333160(u8 *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(u8 *);
extern void func_L19_0044B008(u8 *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L04_00325460(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_L19_00332D38(void *);

void func_L19_00332948(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *pv = *(u8 **)(obj + 0x68);
    u8 *hit;
    s32 t;

    if (obj[0x20] == 0) {
        func_L19_00333160(obj);
    }
    if (obj[0x20] != 0x17 && (*(unsigned long *)(obj + 0x30) & 0x104100000000ul) == 0x4100000000ul && *(s32 *)(obj + 0x98) == 0) {
        u8 *def = *(u8 **)(obj + 0x24);
        u16 f = *(u16 *)(obj + 0x34) & 0xFFBE;
        *(u16 *)(obj + 0x34) = f;
        *(u16 *)(obj + 0x34) = f | (*(u16 *)(def + 0x44) & 0x1000);
        *(s32 *)(obj + 0x98) = *(s32 *)(def + 0x10);
    }
    if (obj[0x31] != 0) {
        if (func_L01_0040E548(D_001E2100, obj + 0x10) < 576.0f) {
            func_L01_004472C0(obj);
            obj[0x6F] = 0x16;
        }
    }
    if (obj[0x20] >= 2 && obj[0x95] != 4 && obj[0x20] != 1) {
        func_L19_0044B008(obj);
    }
    hit = (u8 *)func_L01_00447490(obj, 1, 0);
    if (hit == 0 && !(*(f32 *)(obj + 0x18) <= *(f32 *)(pv + 0x3BC))) {
        goto after;
    }
    if ((*(unsigned long *)(obj + 0x30) & 0x104100000000ul) == 0x4100000000ul && *(s32 *)(obj + 0x98) == 0) {
        goto after;
    }
    if (!(*(f32 *)(obj + 0x18) <= *(f32 *)(pv + 0x3BC))) {
        u8 *other;
        if (hit == 0 || (other = *(u8 **)(hit + 0x20)) == 0 || *(s16 *)(other + 0xAA) != 0x1A8E) {
            t = D_001DCBD4_sda - D_L19_001DF240;
            if (t <= 0) {
                t = -t;
            }
            if (!(D_001DCBD8_sda < t)) {
                obj[0xA8] = 0xFF;
                goto after;
            }
        }
    }
    D_001DCBD4_sda = D_L19_001DF240;
    func_L04_00325460(obj + 0x10, 0, 5, 5, 5, 10, 20, 0, 1, 0, 0, 0, 0.25f, 20.0f);
    if (*(s16 *)(obj + 0xAA) == 0x964) {
        func_L01_00451FE0(obj, 15, pv + 0x1E0, 255, 180, 0, 0, 35, 0, 3,
                          3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    }
    *(s32 *)(obj + 0x98) = 0;
    *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(obj, 1);
    func_L01_004450F0(obj, 0x17, 0);
    obj[0xA8] = 0xFF;
after:
    if (obj[0x95] == 4) {
        D_001DF42E[0]++;
    }
    if (!((*(unsigned long *)(obj + 0x30) & 0x104100000000ul) == 0x4100000000ul && *(s32 *)(obj + 0x98) == 0) && obj[0x20] != 1) {
        if (func_0038CF38(obj + 0x10, D_1A4C60) < 16.0f) {
            D_001DF42C[0]++;
            switch (*(s16 *)(obj + 0xAA)) {
            case 0x940:
                D_001DF430[0]++;
                break;
            case 0x93C:
                D_001DF432[0]++;
                break;
            case 0xA59:
                D_001DF434[0]++;
                break;
            }
        }
    }
    func_L19_00332D38(obj);
}

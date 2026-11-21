/* functional: high. PAL port of the NTSC draft's state machine, re-derived from the PAL asm (PAL thresholds: 1000 ticks, 25 frames, 0x32/0x65/0x97; gp globals at PAL addresses 0x1DEA34.. and 0x1DEA44). Bytes differ (154 words, same structure/scheduling shifts). Switch cases 0-4 assumed in jump-table order (table jtbl_002C1BD0 not read). */
typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    u8 *marker;
    s16 f44, f46;
    s32 f48, f4C;
} PV_3C6708;
extern s32 D_001D66D4_sda;
extern s32 D_L19_001D66D0, D_L19_001E6470[];
extern u8 *D_L19_001DF71C, *D_L19_001DF800;
extern u8 *D_001DF71C_sda;
extern u8 D_001A4C60[], D_001A4BE0[], D_0014270B[], D_0014270C[], D_001A71C4[];
extern u32 D_00142C54[];
extern s32 D_001A8000[], D_001D545C;
extern u8 D_001BBC40[], D_L19_001E2080[];
extern f32 D_L19_001DEA34_sda, D_L19_001DEA38_sda, D_L19_001DEA3C_sda, D_L19_001DEA40_sda;
extern s32 D_L19_001DEA44_sda, D_L19_001DF758_sda;
extern u16 D_L19_001DF42C;
extern s16 *D_L19_0021C260[];
extern f32 D_L19_001DF050[];
extern s32 func_L01_0044C108(void *);
extern void func_003C2880(void *);
extern void func_L19_003C6F18(void *);
extern void func_L19_003C6F30(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_0039EF28(void);
extern void func_L19_003BED90(void *, void *, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_0041A5B0(s32, s32);
extern u8 *func_L01_003F2A50(s32, s32);
extern void func_L16_00402D30(s32, void *);
extern void func_L01_003F2AF8(s32, void *);
extern s32 func_L01_00456250(void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_003EB5E0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00511A40(void *, s32, f32);
extern void func_003C4138(void *, f32, f32);
extern void func_L01_0043B510(s32);
extern void func_L19_003C7058(void *);

__asm__(".extern D_001D66D4_sda, 4");
__asm__(".extern D_001DF71C_sda, 4");
__asm__(".extern D_L19_001DEA34_sda, 4");
__asm__(".extern D_L19_001DEA38_sda, 4");
__asm__(".extern D_L19_001DEA3C_sda, 4");
__asm__(".extern D_L19_001DEA40_sda, 4");
__asm__(".extern D_L19_001DEA44_sda, 4");
__asm__(".extern D_L19_001DF758_sda, 4");
void func_L19_003C6708(u8 *o) {
    vu0_v4 sum, rotation;
    PV_3C6708 *v;
    u8 *m, *p;
    s16 *list;
    f32 count;
    s32 all;
    v = *(PV_3C6708 **)(o + 0x68);
    if (!func_L01_0044C108(o + 0x10)) return;
    if ((u32)(D_001D66D4_sda - 1) < 2 || D_L19_001D66D0 == 1 || D_L19_001D66D0 == 2) {
        if (D_L19_001E6470[0] == 1) {
            m = D_L19_001DF71C + (v->f4C << 8);
            if (m) func_003C2880(m);
        }
        return;
    }
    switch (o[0x20]) {
    case 0:
        func_L19_003C6F18(o);
        func_L01_004450F0(o, 1, -1);
        break;
    case 1:
        if (func_00382380(D_001A4C60, v->f14, 0) || D_001A4C60[0x2564] == 1) {
            D_0014270B[0] = 1;
            func_0039EF28();
            func_L01_004450F0(o, 2, -1);
        }
        break;
    case 2:
        if (D_001A71C4[0] != 1) func_L19_003C6F30(o);
        p = D_L19_001DF800 + (v->f0C << 7);
        func_L19_003BED90(D_L19_001DF71C + (v->f04 << 8), p + 0x30, p + 0x70);
        func_L01_004450F0(o, 3, -1);
        break;
    case 3: {
        u8 *mobys = D_001DF71C_sda;
        if (D_00142C54[0] & 0x800000) {
            if (((unsigned long)0x8200 << 23) == (*(unsigned long *)(mobys + (v->f04 << 8) + 0x30) & ((unsigned long)0x8208 << 29)) && *(s32 *)(mobys + (v->f04 << 8) + 0x98) == 0) {
                *(u16 *)(mobys + (v->f04 << 8) + 0x34) &= 0xFFBE;
                *(u16 *)(mobys + (v->f04 << 8) + 0x34) |= *(u16 *)(*(u8 **)(mobys + (v->f04 << 8) + 0x24) + 0x44) & 0x1000;
                *(s32 *)(mobys + (v->f04 << 8) + 0x98) = *(s32 *)(*(u8 **)(mobys + (v->f04 << 8) + 0x24) + 0x10);
                *(u16 *)(mobys + (v->f04 << 8) + 0x34) &= 0xFFFD;
            }
            m = D_L19_001DF71C + (v->f4C << 8);
            if (m && m[0x20] != 0xFE && m[0x20] != 0xFD) func_003C2880(m);
        } else {
            if (((unsigned long)0x8200 << 23) != (*(unsigned long *)(mobys + (v->f04 << 8) + 0x30) & ((unsigned long)0x8208 << 29)) || *(s32 *)(mobys + (v->f04 << 8) + 0x98) != 0) {
                *(u16 *)(mobys + (v->f04 << 8) + 0x34) |= 0x41;
                *(u16 *)(mobys + (v->f04 << 8) + 0x34) &= 0xEFFF;
                *(s32 *)(mobys + (v->f04 << 8) + 0x98) = 0;
                func_L01_004AA7E8(mobys + (v->f04 << 8), 1);
                *(u16 *)(D_L19_001DF71C + (v->f04 << 8) + 0x34) |= 2;
            }
        }
        if (func_00382380(D_001A4C60, v->f38, 0)) {
            if (++v->f46 > 1000) {
                if (D_001A8000[0] >= 0) func_L01_0041A5B0(0xB85, 0x28);
                v->f46 = 0;
            }
            if (v->marker == 0) {
                v->marker = func_L01_003F2A50(0, 5);
                if (!v->marker) goto marker_done;
            }
            *(f32 *)(v->marker + 8) = D_L19_001DEA34_sda;
            *(f32 *)(v->marker + 4) = D_L19_001DEA38_sda;
            *(f32 *)(v->marker) = D_L19_001DEA3C_sda;
            func_L16_00402D30(0, v->marker);
        } else if (v->marker) {
            func_L01_003F2AF8(0, v->marker);
            v->marker = 0;
        }
marker_done:
        if (func_00382380(D_001A4C60, v->f3C, 0)) *(f32 *)(D_001A4C60 + 0x19DC) = D_L19_001DEA40_sda;
        else *(f32 *)(D_001A4C60 + 0x19DC) = 0.0f;
        *(s32 *)(*(u8 **)(D_L19_001DF71C + (v->f28 << 8) + 0x68) + 0xC) = func_L01_00456250(D_L19_001DF71C + (v->f2C << 8));
        D_L19_001DF42C++;
        if (v->f24 >= 0 && func_00382380(D_001A4C60, v->f24, 0)) {
            if (!D_L19_001DEA44_sda) {
                if (++v->f44 > 25) {
                    func_L01_003EB438(0, D_L19_001E2080, D_L19_001E2080 + 0x10, 0, 0, 0);
                    func_L01_003EB350(0, D_L19_001DF800 + (v->f34 << 7) + 0x30);
                    D_L19_001DEA44_sda = 1;
                    v->f24 = -1;
                }
            } else {
                v->f24 = -1;
                v->f30 = -1;
            }
        }
        if (D_L19_001DEA44_sda && v->f30 >= 0) {
            qzero(&sum);
            count = 0.0f;
            all = 1;
            list = D_L19_0021C260[v->f30];
            while ((v->f30 & 0xFF) != 0xFF && v->f30 <= D_L19_001DF758_sda && list && (list[-1] >= 0 || list == D_L19_0021C260[v->f30])) {
                m = D_L19_001DF71C + ((*(u16 *)list & 0x7FFF) << 8);
                if (!m) break;
                vec_add_ab(&sum, &sum, (vu0_v4 *)(m + 0x10));
                count += 1.0f;
                if (m[0x20] != 2) all = 0;
                list++;
            }
            func_0038CE20(&sum, &sum, 1.0f / count);
            rotation.x = 0.0f;
            rotation.y = -func_0038D160(func_0038CF38(D_L19_001DF800 + (v->f34 << 7) + 0x30, &sum), sum.z - *(f32 *)(D_L19_001DF800 + (v->f34 << 7) + 0x38));
            p = D_L19_001DF800 + (v->f34 << 7);
            rotation.z = func_0038D160(sum.x - *(f32 *)(p + 0x30), sum.y - *(f32 *)(p + 0x34));
            func_L01_003EB3C0(0, &rotation);
            if (all) {
                *(f32 *)(D_001A4BE0 + 0x98) = func_0038D160(sum.x - *(f32 *)(D_001A4BE0 + 0x80), sum.y - *(f32 *)(D_001A4BE0 + 0x84));
                func_L01_003EB5E0(0, 2);
                v->f30 = -1;
            }
        }
        if (func_L01_00456250(D_L19_001DF71C + (v->f20 << 8))) func_L01_004450F0(o, 4, -1);
        if ((D_001BBC40[v->f10 + (D_001D545C << 4)] & 0x80) && func_00382380(D_001A4C60, v->f18, 0)) func_L01_004450F0(o, 4, -1);
        break;
    }
    case 4:
        if (*(u16 *)(o + 0x96) == 0x32) {
            p = D_L19_001DF800 + (v->f48 << 7);
            func_L01_00511A40(p + 0x30, 0, *(f32 *)(p + 0x78));
        }
        if (*(u16 *)(o + 0x96) >= 0x65) func_003C4138(D_L19_001DF050, 1.0f, 0.35f);
        if (*(u16 *)(o + 0x96) >= 0x97) {
            func_L01_0043B510(v->f10);
            D_0014270C[0] = 1;
            func_0039EF28();
            func_L19_003C7058(o);
            func_L01_004450F0(o, 1, -1);
        }
        break;
    }
    if (*(u16 *)(o + 0x96) < 0xFFFF) ++*(u16 *)(o + 0x96);
}

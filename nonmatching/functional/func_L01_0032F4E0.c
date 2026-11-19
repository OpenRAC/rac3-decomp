/* functional: high. Vector add/sub done with plain f32 fields (vadd/vsub.xyz keep w); stack args weave=0,unk_81=0 passed to spawner; diff to retail is scheduling only. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_32F4E0;
extern s32 D_001DFB40;
__asm__(".extern D_001DCEC8_sda, 4");
extern s32 D_001DCEC8_sda;
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_004C7D98(void *, void *);
extern void *func_00382348(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern u8 *func_L01_00344A88(void *, void *, u8, u8, u8, u8, u16, void *, f32, f32, f32, f32, s32, s32);

void func_L01_0032F4E0(u8 *moby) {
    V4_32F4E0 pos;
    V4_32F4E0 m10;
    V4_32F4E0 tpos;
    V4_32F4E0 dir;
    V4_32F4E0 off;
    u8 *st = *(u8 **)(moby + 0x68);
    u8 *m;
    u8 *r;
    u8 *tgt;

    if (D_001DFB40 & 1) {
        func_003C2F58(moby, 1, &pos);
    } else {
        func_003C2F58(moby, 2, &pos);
    }
    func_L01_004C7D98(moby + 0x10, &m10);
    if (*(f32 *)(st + 0x5C) == 0.0f) {
        if (*(s32 *)(st + 0x50) != 0 && *(s32 *)(st + 0x64) != 0) {
            r = func_00382348(*(void **)(st + 0x64));
            tgt = *(u8 **)(st + 0x64);
            tpos = *(V4_32F4E0 *)(tgt + 0x10);
            if (r != 0) {
                func_0038CE20(&off, *(u8 **)(st + 0x64) + 0xE0, *(f32 *)(r + 0x10));
                tpos.x = tpos.x + off.x;
                tpos.y = tpos.y + off.y;
                tpos.z = tpos.z + off.z;
            }
            dir = tpos;
            dir.x = tpos.x - pos.x;
            dir.y = tpos.y - pos.y;
            dir.z = tpos.z - pos.z;
            func_0038CF68(&dir, &dir, *(f32 *)(D_L01_002C5600 + D_001425C0[0x15] * 0xF0 + 0x4C) * 0.02f);
            func_L01_004AAC98(0, 0, moby, 0x1367);
            m = func_L01_00344A88(&pos, &dir, 0x50, 0xC8, 1, 0, 0x10E, *(void **)(st + 0x64), 2.0f, 15.0f, 0.5f,
                                  *(f32 *)(D_L01_002C5600 + D_001425C0[0x15] * 0xF0 + 0x6C), 0, 0);
            if (m != 0) {
                *(s32 *)(m + 0xB8) = *(s32 *)(st + 0x68);
            }
            *(s32 *)(st + 0x44) = 5;
            *(s32 *)(st + 0x60) = *(s32 *)(st + 0x60) - 1;
            *(s32 *)(st + 0x40) = (D_001DCEC8_sda * 5 + 2) / 6;
            if (*(s32 *)(st + 0x60) <= 0) {
                moby[0x20] = 8;
            }
            *(f32 *)(st + 0x5C) = 0.41666669f;
        }
    }
}

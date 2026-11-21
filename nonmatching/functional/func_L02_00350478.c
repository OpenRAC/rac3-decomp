/* functional: medium. Written from PAL asm; compiles at level 02 with the file flags (843 diff, layout/regalloc). Two jump-table-free switches: self[0x95] (phase) then self[0x20] (jtbl_002BCA70, states 2..10). The two identical particle sprays are a static helper (puff_00350478); the vec subtract is plain float math (file has no VU0 flag), same xyz and w=p+0x22C. func_L02_0039CD18 retail also zeroes a3, which its C ignores. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_350478;
extern s32 func_L02_00351208(void *);
extern void func_L02_003516A8(void *);
extern void func_L02_003516C8(void *);
extern void *func_L02_0039CD18(void *, void *, void *, f32);
extern void func_003C2880(void *);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038CB00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern void func_L01_003016B0(void *, s32, f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_00468A68(void *, void *, s32, s32);
extern void func_L01_00315900(void *, s32, s32);
extern f32 func_0038D160(f32, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0045A748(void *, void *);
extern f32 func_L01_004395E0(void *);
extern void func_L01_004468C8(u8 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);

static void puff_00350478(u8 *self, f32 range) {
    V4_350478 v[3];
    f32 h, h2, a, b, c;
    s32 cnt, k, m;
    if (func_L01_0044E1B8(self, range) == 0) return;
    h = func_003C3D30(self + 0x10, 0, self, 2.0f);
    h2 = h + 0.2f;
    v[0] = *(V4_350478 *)(self + 0x10);
    v[0].z = h2 - 0.2f;
    func_L01_003016B0(v, 3, 9.0f, 1.02f);
    func_L01_003016B0(v, 3, 9.0f, 1.02f);
    for (cnt = 20; cnt != 0; cnt--) {
        a = func_00382538();
        b = func_003824E0(0.0f, 0.06f);
        v[1].x = func_0038D098(a) * b;
        v[1].y = func_0038D0B0(a) * b;
        v[1].z = func_003824E0(0.06f, 0.16f);
        c = v[1].x * 8.0f;
        v[2].y = v[0].y + c;
        v[2].x = v[0].x + c;
        v[2].z = h2 - func_003824E0(0.0f, 0.2f);
        k = func_00382468(2);
        m = func_00382498(0x5A, 0x78);
        func_L01_00468A68(v, v + 1, k, m);
    }
}

static void face_00350478(u8 *self, u8 *p) {
    func_L01_0045BD10(self, func_0038D160(*(f32 *)(p + 0x220) - *(f32 *)(self + 0x10), *(f32 *)(p + 0x224) - *(f32 *)(self + 0x14)));
}

void func_L02_00350478(u8 *self) {
    u8 *p = *(u8 **)(self + 0x68);
    s32 flags, t, x;
    f32 d;
    V4_350478 v0, v10;

    if (func_L02_00351208(self) != 0) {
        func_003C2880(self);
        return;
    }
    switch (self[0x95]) {
    case 0:
        if (func_L01_004561E0(self) != 0 && *(s16 *)(p + 0x2D6) == 0) {
            *(s16 *)(p + 0x2D6) = (func_00382498(0, 0x28) * 5 + 2) / 6;
        }
        if (*(s16 *)(p + 0x234) == 1 && func_0038CB00(p + 0x2D6) != 0) {
            u8 *o = *(u8 **)(self + 0x24);
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) & 0xFFBE) | (*(u16 *)(o + 0x44) & 0x1000);
            *(s32 *)(self + 0x98) = *(s32 *)(o + 0x10);
            func_L01_004450F0(self, 3, 2);
            if (self[0x43] != 0xB) func_003C3A10(self, 0xB, 0, (func_00382498(6, 0xE) * 5 + 2) / 6);
            if (func_00382468(2) != 0 && *(s32 *)(p + 0x2DC) == 0 && self[0x43] != 0xC) {
                func_003C3A10(self, 0xC, 0, (func_00382498(6, 0xE) * 5 + 2) / 6);
            }
        } else if (*(s32 *)(p + 0x2D8) != 0 && func_0038CB00(p + 0x2D6) != 0) {
            func_L01_004450F0(self, 2, 1);
            *(s32 *)(p + 0x2D8) = 0;
            if (*(s32 *)(p + 0x2D0) < 0xFA) {
                *(s32 *)(p + 0x2D0) = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 1:
        if (*(s16 *)(p + 0x234) == 1) {
            if (self[0x43] != 7) func_003C3A10(self, 7, 0, 0x11);
            func_L01_004450F0(self, 8, 2);
        } else if (*(s32 *)(p + 0x2D0) == 0) {
            func_L01_004450F0(self, 1, 0);
        }
        break;
    case 2:
        if (*(s16 *)(p + 0x234) != 1 && self[0x20] != 3 && self[0x20] != 8 && self[0x20] != 9) {
            if (self[0x43] != 0xF) func_003C3A10(self, 0xF, 0, 0x15);
            func_L01_004450F0(self, 2, 1);
            *(s32 *)(p + 0x2D0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
        }
        break;
    case 3:
        flags = func_L01_00454370(self, p + 0x160);
        if (func_L01_004561E0(self) != 0 && self[0x43] == 0x10) func_003A52A0(4, 0, self);
        t = self[0x42];
        if (t == 2 || t == 0x10) puff_00350478(self, 25.0f);
        if ((flags & 1) && self[0x42] != 0x10) goto leave3;
        if (self[0x42] == 0x10 && func_L01_0044E1B8(self, 38.0f) != 0) goto leave3;
        if (flags & 2) {
            if (0.0f < *(f32 *)(p + 0x30)) {
                if (self[0x43] != 4) func_003C3A10(self, 4, 0, 8);
                if (*(s16 *)(p + 0x234) == 1) {
                    func_L01_004450F0(self, 4, 2);
                } else {
                    func_L01_004450F0(self, 2, 1);
                    *(s32 *)(p + 0x2D0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
                }
            }
        }
        break;
    leave3:
        func_L02_003516A8(self);
        func_L01_00315900(self, 0, 0);
        return;
    }
    switch (self[0x20]) {
    case 2:
        if (self[0x42] == 0xF) {
            if ((self[0x60] & 2) != 0 && self[0x43] != 1) func_003C3A10(self, 1, 0, 0x15);
        } else if (self[0x42] == 1) {
            if ((self[0x60] & 2) != 0 && self[0x43] != 0xF) func_003C3A10(self, 0xF, 0, 0x15);
        }
        break;
    case 3:
        if (self[0x42] == 0xB) puff_00350478(self, 2.0f);
        face_00350478(self, p);
        if ((self[0x60] & 2) == 0) break;
        if (func_0038CF38(self + 0x10, p + 0x220) < 9.0f) goto near;
        if (self[0x43] != 7) func_003C3A10(self, 7, 0, (func_00382498(0xA, 0xF) * 5 + 2) / 6);
        func_L01_004450F0(self, 8, -1);
        break;
    case 4:
        face_00350478(self, p);
        if (func_0038CF38(self + 0x10, p + 0x220) < 9.0f) goto near;
        if (self[0x43] != 7) func_003C3A10(self, 7, 0, (func_00382498(8, 0x14) * 5 + 2) / 6);
        func_L01_004450F0(self, 8, -1);
        break;
    case 5:
        func_L01_0045A748(self, p + 0x220);
        if (func_0038CF38(self + 0x10, p + 0x220) < 7.0f) goto near;
        break;
    case 6:
        face_00350478(self, p);
        if ((self[0x60] & 2) == 0) break;
        func_L01_004450F0(self, 7, -1);
        if (self[0x43] != 9) func_003C3A10(self, 9, 0, 3);
        break;
    case 7:
        if ((self[0x60] & 2) != 0) {
            func_L01_004450F0(self, 0xA, -1);
            if (self[0x43] != 0xF) func_003C3A10(self, 0xF, 6, 0x19);
        }
        d = func_L01_004395E0(self);
        if (d < 3.0f || 18.0f < func_L01_004395E0(self)) face_00350478(self, p);
        if (!(func_L01_004395E0(self) < 10.0f)) break;
        func_L01_004468C8(self, 1, 0x10008, 0, 1, 0, 1.75f, (f32)p[0x45], 2.5f);
        func_L01_004468C8(self, 2, 0x10008, 0, 1, 0, 1.5f, (f32)p[0x45], 2.5f);
        break;
    case 8:
        face_00350478(self, p);
        if ((self[0x60] & 2) == 0) break;
        func_L01_004450F0(self, 9, -1);
        if (self[0x43] != 0xA) func_003C3A10(self, 0xA, 0, 8);
        break;
    case 9:
        face_00350478(self, p);
        if (func_L01_0044E1B8(self, 32.0f) != 0 && self[0x42] == 0xA) {
            func_L01_004450F0(self, 0xA, -1);
            if (self[0x43] != 0xF) func_003C3A10(self, 0xF, 4, (func_00382498(0x19, 0x1E) * 5 + 2) / 6);
            if (func_00382468(6) == 0 && self[0x43] != 0) func_003C3A10(self, 0, 0xA, 0x19);
        }
        if (func_L01_0044E1B8(self, 8.0f) != 0) {
            func_003C2F58(self, 0, &v0);
            v10.x = *(f32 *)(p + 0x220) - v0.x;
            v10.y = *(f32 *)(p + 0x224) - v0.y;
            v10.z = *(f32 *)(p + 0x228) - v0.z;
            v10.w = *(f32 *)(p + 0x22C);
            func_0038CF68(&v10, &v10, 0.6f);
            func_L02_0039CD18(self, &v10, &v0, (f32)p[0x44]);
        }
        break;
    case 10:
        if (func_L01_004561B8(self) != 0) {
            *(f32 *)(self + 0x48) = func_003824E0(0.85f, 1.15f);
        }
        face_00350478(self, p);
        if ((self[0x60] & 2) == 0) break;
        func_L01_004450F0(self, 4, -1);
        if (self[0x43] != 0xD) func_003C3A10(self, 0xD, 0, 0x15);
        break;
    }
    func_L02_003516C8(self);
    return;
near:
    if (self[0x43] != 6) func_003C3A10(self, 6, 0, 8);
    func_L01_004450F0(self, 6, -1);
    func_L02_003516C8(self);
}

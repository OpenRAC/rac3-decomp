/* functional: medium. Written from the disassembly; every branch of the state switch, the trigger checks and the shot are read against it. Callee func_L01_00309B80 and func_003A52A0 are declared here as the file's later code and the asm use them (func_L01_00309B80 is declared later in this file with s128 pointer types: the lead must reconcile that declaration). */
extern u8 D_001A4BE0[];
extern u8 *D_001D52FC;
extern u8 D_1425D0;
extern s32 D_001E1700;
extern f32 D_001E171C;
extern u8 D_001E29E0[];
extern u8 D_0026FB30[];
extern s32 D_001DC600_sda;
extern s32 D_001DC5E8_sda;
extern f32 D_001DC5F4_sda;
extern f32 D_001DC5F8_sda;
extern f32 D_001DC5EC_sda;
extern f32 D_001DC5FC_sda;
extern f32 D_001DC5F0_sda;
extern u8 *D_001DC604_sda;
extern s32 D_001DC608_sda;
__asm__(".extern D_001DC600_sda, 4");
__asm__(".extern D_001DC5E8_sda, 4");
__asm__(".extern D_001DC5F4_sda, 4");
__asm__(".extern D_001DC5F8_sda, 4");
__asm__(".extern D_001DC5EC_sda, 4");
__asm__(".extern D_001DC5FC_sda, 4");
__asm__(".extern D_001DC5F0_sda, 4");
__asm__(".extern D_001DC604_sda, 4");
__asm__(".extern D_001DC608_sda, 4");
extern u8 D_002C5600[];
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_0043A430(void *, s32, void *);
extern s32 func_L01_004572B0(u8 *, void *, s32 *);
extern void *func_L01_00457480(s32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_005003D0(s32, s32);
extern u32 func_L01_004CB1F0(f32, f32);
extern void func_L01_003F6F20(s32, u8 *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_0040E050(void *);
extern s32 func_L01_0030A130(void);
extern s32 func_L01_005118D0(s32, s32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_003C2F58(u8 *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00457588(u8 *, void *, void *, f32);
extern u8 *func_L01_00309B80(u8 *, s32, void *, void *);
extern void func_L01_00404A10(void *, u8 *);
extern void func_L01_00307858(void);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);

/* lava_gun_update: the Lava Gun's per-frame handler (state 0 sets up the gun's ring of 4 flame
   records, state 1 runs the trigger: charge up while held, fire at the threshold, then cool). */
void func_L01_003071C8(u8 *self)
{
    u8 *p = *(u8 **)(self + 0x68);
    s32 ok = 1;
    s32 phase;
    s32 i;
    u8 *q;
    u8 *row;
    f32 c;
    f32 lim;
    s32 handle;
    u8 vel[16];
    u8 pos[16];
    s32 out[4];

    if (*(s32 *)(D_001A4BE0 + 0x25C4) == 0x1D) {
        if (!func_0038CAD0(D_001A4BE0 + 0x28BC)) {
            ok = 0;
        }
    } else {
        *(s32 *)(D_001A4BE0 + 0x28BC) = 0x21;
    }
    if (*(s32 *)(D_001A4BE0 + 0x1430) != 0) {
        *(s32 *)(D_001A4BE0 + 0xBD8) = *(s32 *)(D_001A4BE0 + 0x1430);
    }
    if (self[0x20] == 0) {
        *(f32 *)p = 0.36666667f;
        self[0x20] = 1;
        D_001E171C = -1.0f;
        D_001DC600_sda = 0;
        D_001DC5E8_sda = 0;
        if (self[0x43] != 0 || (self[0x60] & 2)) {
            func_003C3A10(self, 1, 0, 0);
        }
        *(f32 *)(p + 0xC) = 0;
        *(f32 *)(p + 0x10) = 0;
        func_L01_0043A430(self, 0, p + 0x20);
        handle = func_L01_004572B0(self, 0, out);
        *(s32 *)(p + 4) = handle;
        *(void **)(p + 8) = func_L01_00457480(*(s16 *)(self + 0xAA), handle);
        for (i = 0; i < 4; i++) {
            q = D_0026FB30 + i * 0x80;
            *(s32 *)(q + 0x0) = 0;
            *(s32 *)(q + 0x4) = 0;
            *(s32 *)(q + 0x8) = 0;
            *(f32 *)(q + 0xC) = func_L01_00443A18(0.05f, 0.3f);
            *(f32 *)(q + 0x10) = func_L01_00443A18(0.05f, 0.3f);
            *(f32 *)(q + 0x14) = func_L01_00443A18(0.05f, 0.3f);
            *(f32 *)(q + 0x18) = func_003824E0(0.25f, 0.75f);
            *(f32 *)(q + 0x1C) = func_003824E0(0.25f, 0.75f);
            *(f32 *)(q + 0x20) = func_003824E0(0.25f, 0.75f);
            *(s32 *)(q + 0x24) = 0;
            *(s32 *)(q + 0x28) = 0;
            *(s32 *)(q + 0x2C) = 0;
            *(f32 *)(q + 0x30) = func_L01_00443A18(0.05f, 0.3f);
            *(f32 *)(q + 0x34) = func_L01_00443A18(0.05f, 0.3f);
            *(f32 *)(q + 0x38) = func_L01_00443A18(0.05f, 0.3f);
            *(f32 *)(q + 0x3C) = func_003824E0(0.25f, 0.75f);
            *(f32 *)(q + 0x40) = func_003824E0(0.25f, 0.75f);
            *(f32 *)(q + 0x44) = func_003824E0(0.25f, 0.75f);
            *(s32 *)(q + 0x50) = 0;
            *(s32 *)(q + 0x54) = 0;
            *(s32 *)(q + 0x58) = 0;
            *(s32 *)(q + 0x5C) = 0;
            *(s32 *)(q + 0x60) = 0;
            *(s32 *)(q + 0x64) = 0;
            *(s32 *)(q + 0x68) = 0;
            *(s32 *)(q + 0x6C) = 0;
        }
        return;
    }
    if (self[0x20] != 1) {
        return;
    }
    D_001E171C = -1.0f;
    if (D_001DC5E8_sda == 0) {
        *(f32 *)(p + 0xC) = 0;
        D_001DC5E8_sda = 1;
    }
    if (*(s32 *)(D_001A4BE0 + 0x25C4) == 1) {
        func_L01_005003D0(0x1D, 1);
    }
    if (*(s32 *)(D_001A4BE0 + 0x25C4) == 0x1D || *(s32 *)(D_001A4BE0 + 0x16B0) != 0) {
        func_L01_003F6F20(0, self, func_L01_004CB1F0(1.0f, 150.0f), 0, 0x21, -1, 4,
                          0.8f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
    } else {
        *(s32 *)(D_001A4BE0 + 0x16D8) = 0;
        *(s32 *)(D_001A4BE0 + 0x16D4) = 0;
    }
    phase = D_001DC600_sda;
    if (func_L01_0040E050(p)) {
        phase = D_001DC600_sda;
        if (ok) {
            if (D_001A4BE0[0x25ED] == 0
                && (*(s32 *)(D_001D52FC + 0x1A0) & *(s32 *)(D_001A4BE0 + 0x1210)) != 0
                && func_L01_0030A130() == 0
                && *(s32 *)(D_001A4BE0 + 0x1220) >= 0x13) {
                if (func_L01_005118D0(-1, 1)) {
                    D_001E1700 = 1;
                    func_003A52A0(2, 0, self);
                    if (D_001DC600_sda == 0) {
                        D_001DC600_sda = 1;
                        *(f32 *)(p + 0xC) = D_001DC5F4_sda;
                        row = D_002C5600 + D_1425D0 * 0xF0;
                        *(f32 *)p = 1.0f / *(f32 *)(row + 0x50);
                    } else if (D_001DC600_sda == 2) {
                        row = D_002C5600 + D_1425D0 * 0xF0;
                        D_001DC600_sda = 1;
                        *(f32 *)p = 1.0f / *(f32 *)(row + 0x50);
                    }
                } else {
                    if ((*(s32 *)(D_001D52FC + 0x1A4) & *(s32 *)(D_001A4BE0 + 0x1210)) != 0 || D_001E1700 == 1) {
                        func_003A52A0(6, 0, self);
                        D_001E1700 = 0;
                    }
                }
                phase = D_001DC600_sda;
            } else {
                phase = D_001DC600_sda;
            }
        } else {
            phase = D_001DC600_sda;
        }
    } else {
        phase = D_001DC600_sda;
    }
    if (phase == 0) {
        c = *(f32 *)(p + 0xC);
        lim = D_001DC5F4_sda;
        if (c < lim) {
            c = c + D_001DC5F8_sda;
            *(f32 *)(p + 0xC) = c;
            if (lim < c) {
                *(f32 *)(p + 0xC) = lim;
            }
        }
    } else if (phase == 1) {
        c = *(f32 *)(p + 0xC) + D_001DC5EC_sda;
        *(f32 *)(p + 0xC) = c;
        if (D_001DC5FC_sda < c) {
            func_003C2F58(self, 0, pos);
            if (*(s16 *)(D_001A4BE0 + 0x2874) == 1) {
                func_0038CF68(vel, self + 0xD0, -0.40000004f);
            } else if (*(s32 *)(D_001A4BE0 + 0x16B0) == 1) {
                func_0038CF68(vel, D_001E29E0, 0.40000004f);
            } else {
                func_0038CF68(vel, D_001A4BE0 + 0x6F0, 0.40000004f);
            }
            if (*(s32 *)(D_001A4BE0 + 0xBD8) != 0) {
                func_L01_00457588(*(u8 **)(D_001A4BE0 + 0xBD8), pos, vel, 0.40000004f);
            }
            D_001DC604_sda = func_L01_00309B80(self, *(s32 *)(p + 4), pos, vel);
            if (D_001DC604_sda != 0) {
                *(u8 **)(D_001DC604_sda + 0xB8) = self;
            }
            D_001DC608_sda = 0x2A;
            D_001DC600_sda = 2;
        }
    } else if (phase == 2) {
        c = *(f32 *)(p + 0xC) - D_001DC5F0_sda;
        lim = D_001DC5F4_sda;
        *(f32 *)(p + 0xC) = c;
        if (c <= lim) {
            *(f32 *)(p + 0xC) = lim;
            D_001DC600_sda = 0;
        }
    }
    if (self[0x31] != 0) {
        func_L01_00404A10(func_L01_00307858, self);
    }
    *(f32 *)(p + 0x10) = func_0038DAB8(*(f32 *)(p + 0x10), *(f32 *)(p + 0xC) * 0.37699115f);
    *(f32 *)(p + 0x30) = func_0038D0B0(*(f32 *)(p + 0x10) * 0.5f);
    *(f32 *)(p + 0x3C) = func_0038D098(*(f32 *)(p + 0x10) * 0.5f);
}

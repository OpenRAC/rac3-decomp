/* functional: medium. Callees the catalogue folds (8/12/28-byte return-0, gp-slot getter/setter and jal wrappers, and the 1460-byte 004E20E8, whose catalogue places in other levels are other copies than the ones this function calls there) are named as aliases func_L01_XXXXXXXX_004B8ED0, read from the bytes in each level. Fixed: callees at 0047B388/004792A8 are func_003E4D10/func_003E54E0 (were wrongly func_L01_*); level gp slots named D_L01_XXXXXXXX (no _sda). Per-frame level control (pause/menu/exit prompts, hero-triggered dialogs, then the normal frame update calls); all branches re-read against asm, the a0 left in a register for func_L01_00514490 (retail passes 5 untouched) is written as no argument because the callee takes none; hero/state field names are mine. */
typedef struct {
    u8 pad0[0x1E0];
    s16 h1E0;
    u8 pad1E2[0x121C - 0x1E2];
    u8 b121C;
    u8 pad121D[0x1228 - 0x121D];
    s32 w1228;
    u8 pad122C[0x19E0 - 0x122C];
    u8 *obj19E0;
    u8 pad19E4[0x25C4 - 0x19E4];
    s32 state;
    u8 pad25C8[4];
    s32 w25CC;
    u8 pad25D0[0x25E4 - 0x25D0];
    u8 b25E4;
    u8 pad25E5[0x25F2 - 0x25E5];
    u8 b25F2;
} Hero_004B8ED0;

typedef struct {
    u8 pad0[0x1A4];
    u32 w1A4;
    u32 w1A8;
    u32 w1AC;
} Slot_004B8ED0;

typedef struct {
    u8 pad0[0x6C];
    u16 h6C;
    u8 pad6E[2];
    u32 w70;
    u32 w74;
    u8 pad78[0x1A4 - 0x78];
    u16 h1A4;
    u8 pad1A6[2];
    u32 w1A8;
    u32 w1AC;
} Counters_004B8ED0;

typedef struct {
    u8 pad0[0x1A4];
    u32 flags1A4;
    u8 pad1A8[8];
    u32 flags1B0;
} Game_004B8ED0;

extern Hero_004B8ED0 D_001A4BE0;
extern Counters_004B8ED0 D_001A7C10;
extern Game_004B8ED0 *D_001D52FC;
extern s32 D_001D4CEC_sda;
extern u8 D_001D4CF4;
extern s32 D_001D4C38_sda;
extern s32 D_001D545C_sda;
extern u8 D_00143A06;
extern s32 D_00142660;
extern s32 D_L01_001D6694;
extern u8 D_L01_001D672D;
extern s32 D_L01_001D673C;
extern s32 D_L01_001D6740;
extern s32 D_L01_001D6698;
extern u8 D_L01_001D7EA0[16];
extern s32 D_L01_001DAB2C;
extern u8 D_L01_001DAB30;
extern s32 D_L01_001DFB48;
extern f32 D_L01_001DF950;
extern s32 D_L01_001DFC28;
extern s32 D_L01_001DBCC0;
extern s32 D_L01_001DBCBC;
extern s32 D_L01_001DBCC4;
extern s32 D_L01_002D15F0;

extern s32 func_003A0EC0(s32, s32, s32, s32, s32);
extern s32 func_L01_00432F50(void);
extern s32 func_L01_00432F68(void);
extern s32 func_L01_004B8EC8_004B8ED0(void);
extern s32 func_L01_00514378_004B8ED0(void);
extern s32 func_L01_00514380_004B8ED0(void);
extern s32 func_L01_005143C0(s32);
extern s32 func_L01_00514490(void);
extern void func_L01_00422480(void);
extern void func_00397C90(void);
extern s32 func_00397CA8(void);
extern void func_L01_005075D8(void);
extern s32 func_L01_0045A520_004B8ED0(void);
extern s32 func_L01_0041A518(s32);
extern s32 func_L01_003F08C0_004B8ED0(void);
extern void func_L01_0045A570(s32);
extern void func_L01_0047DA90_004B8ED0(void);
extern void func_L01_00452508(void);
extern void func_003E4D10(s32);
extern void func_003E54E0(s32);
extern void func_003E5520(void);
extern void func_L01_004C8B38(void);
extern void func_L01_00438EA0(void);
extern void func_003CD058(void);
extern void func_L01_004AB0E0(void);
extern void func_L01_004E20E8_004B8ED0(void);
extern void func_003CD350(void);
extern void func_00384D88(void);
extern void func_L01_004A9E58(void);
extern void func_003A4288(void);
extern void func_003D0B20(void);
extern void func_L01_0043AB98(void);
extern void func_00396568(s32);
extern void func_003AF498(void);
extern void func_L01_00478898(void);
extern void func_L01_004788D0(s32);
extern void func_L01_0041AB50(void);
extern void func_003E55B8(void);

void func_L01_004B8ED0(void) {
    Hero_004B8ED0 *hero = &D_001A4BE0;
    s32 flag;
    s32 t;
    s32 st;
    s32 i;
    s32 pad;

    if (D_L01_001D6694 == 0 && D_L01_001D672D == 0 && (D_001D4CEC_sda & 1)) {
        func_003A0EC0(4, 1, 1, 0, 0);
        return;
    }
    if (func_L01_00432F50() != 0 && D_L01_001D6694 == 0 && (D_001D4CEC_sda & 0x600)) {
        if (func_003A0EC0(4, 1, 1, 0, 0) == 0) {
            return;
        }
    }
    if (func_L01_00432F68() != 0 && D_L01_001D6694 == 0 && func_L01_00432F50() != 0) {
        if (func_003A0EC0(4, 1, 1, 0, 0) == 0) {
            return;
        }
    }
    if (func_L01_004B8EC8_004B8ED0() != 0) {
        return;
    }

    /* s16: "hero is in a vehicle-like situation" flag */
    flag = hero->state != 0x31;
    t = 0;
    if (hero->obj19E0 != 0) {
        s32 ty = *(s16 *)(hero->obj19E0 + 0xAA);
        if (ty == 0x905 || ty == 0x85C || ty == 0xEEF || ty == 0x10EE) {
            t = 1;
        }
    }
    flag |= t;
    t = 0;
    if (hero->obj19E0 != 0) {
        t = *(s16 *)(hero->obj19E0 + 0xAA) == 0x1A17;
    }
    flag |= t;
    flag = (flag != 0) | (func_L01_00514378_004B8ED0() != 0);
    flag |= func_L01_005143C0(3) != 0;
    flag |= func_L01_005143C0(5) != 0;
    flag |= func_L01_00514490() != 0;
    func_L01_00422480();

    /* idle-prompt counter */
    if (!(D_001D52FC->flags1B0 & 0x10) || (D_001D52FC->flags1A4 & 0x10) ||
        D_L01_001DFB48 < 8 || hero->b25F2 != 0) {
        goto clear;
    }
    st = hero->state;
    if (st == 0x74 || st == 0x58 || st == 0x39) {
        goto clear_plain;
    }
    if (hero->b121C == 2) {
        goto clear_plain;
    }
    if (st == 0x31) {
        goto clear;
    }
    if (flag == 0) {
        goto clear_plain;
    }
    if (st == 0x1C) {
        goto clear_plain;
    }
    if (D_L01_001D6694 != 0) {
        goto clear;
    }
    if (!(D_L01_001DF950 < 0.2f)) {
        goto clear;
    }
    if (hero->b25E4 >= 2) {
        if (hero->b25E4 != 3) {
            goto clear;
        }
    }
    if (D_L01_002D15F0 != 0) {
        goto clear;
    }
    if (D_00143A06 == 0) {
        goto clear_plain;
    }
    D_L01_001DAB2C = D_L01_001DAB2C + 1;
    if (D_L01_001DAB2C >= 3) {
        D_L01_001DAB2C = 2;
    }
    if (D_L01_001DAB2C >= 2) {
        func_00397C90();
        if (func_00397CA8() != 0) {
            if (hero->b25E4 != 1) {
                func_L01_005075D8();
            }
            func_003A0EC0(4, 1, 7, 0, 0);
            D_L01_001DBCBC = D_L01_001DBCC0;
            D_L01_001DBCC4 = D_L01_001DBCC0;
            return;
        }
    }
    goto after_clear;
clear:
clear_plain:
    D_L01_001DAB2C = 0;
after_clear:

    if (func_L01_0045A520_004B8ED0() == 0) {
        if ((D_001D52FC->flags1A4 & 0x800) || D_001D4CF4 != 0) {
            if (D_L01_001DFB48 >= 8 && hero->state != 0x74 && hero->state != 0x58) {
                if (hero->b121C != 2 || hero->w1228 == 9) {
                    if (flag != 0 && D_L01_001D6694 == 0 && hero->h1E0 == 0) {
                        if (D_L01_001DAB30 != 0) {
                            func_003A0EC0(3, 1, 8, 0, 0);
                        } else if (func_L01_0041A518(D_001D545C_sda) != 0) {
                            func_003A0EC0(3, 1, 5, 0, 0);
                        } else {
                            func_003A0EC0(3, 1, 1, 0, 0);
                        }
                        func_L01_0045A570(func_L01_003F08C0_004B8ED0() != 0);
                        func_L01_0047DA90_004B8ED0();
                        return;
                    }
                }
            }
        }
    }

    /* menu / map button (flags 0x500) */
    if (hero->h1E0 == 0 && D_L01_001DFB48 >= 8 && (D_001D52FC->flags1A4 & 0x500) &&
        hero->w25CC != 0x16) {
        st = hero->state;
        if (st != 0x74) {
            if (st == 0x58) {
                goto call_452508;
            }
            if (flag != 0) {
                if (st == 0x1C) {
                    goto skip_452508;
                }
                if (st == 0xB0) {
                    goto call_452508;
                }
                if (st != 0x16 && st != 0x39 && D_L01_001D6694 == 0) {
                    if (func_L01_00514378_004B8ED0() == 0 || func_L01_00514380_004B8ED0() == 0) {
                        if (func_L01_0041A518(D_001D545C_sda) == 0) {
                            if (D_L01_001D673C != 0 && D_L01_001D6740 == 0) {
                                if (D_001D545C_sda == 0x1A ||
                                    (hero->state != 0x5F && hero->state != 0x5C)) {
                                    func_003A0EC0(4, 1, 6, 0, 0);
                                }
                                if (D_001A7C10.h1A4 <= 0xFFFE) {
                                    D_001A7C10.h1A4 = D_001A7C10.h1A4 + 1;
                                }
                                t = (D_001D4C38_sda * 5 + 2) / 6;
                                if (D_001A7C10.w1A8 < (u32)t) {
                                    D_001A7C10.w1A8 = t;
                                }
                                D_001A7C10.w1AC |= (1 << D_001D545C_sda) | 0x80000000;
                                return;
                            }
                            func_003A0EC0(3, 1, 2, 0, 0);
                            func_L01_0045A570(func_L01_003F08C0_004B8ED0() != 0);
                            if (D_001A7C10.h6C <= 0xFFFE) {
                                D_001A7C10.h6C = D_001A7C10.h6C + 1;
                            }
                            t = (D_001D4C38_sda * 5 + 2) / 6;
                            if (D_001A7C10.w70 < (u32)t) {
                                D_001A7C10.w70 = t;
                            }
                            D_001A7C10.w74 |= (1 << D_001D545C_sda) | 0x80000000;
                            return;
                        }
                    }
                }
            }
        }
    }
call_452508:
    if (hero->state != 0x1C) {
        func_L01_00452508();
    }
skip_452508:
    if ((D_001D52FC->flags1A4 & 0x200) && hero->state != 0x1C && hero->state != 0x31 &&
        hero->b25E4 != 2) {
        if ((u32)(D_001D545C_sda - 0x1E) >= 6) {
            func_003E4D10(0x12C);
            func_003E54E0(0x96);
        }
        t = D_L01_001DFC28;
    } else {
        t = D_L01_001DFC28;
    }
    if (t != 0) {
        if (func_003A0EC0(6, 1, 0, 0, 0) == 0) {
            func_L01_0045A570(func_L01_003F08C0_004B8ED0() != 0);
            D_L01_001DFC28 = 0;
            return;
        }
    }

    /* normal frame */
    func_003E5520();
    func_L01_004C8B38();
    func_L01_00438EA0();
    func_003CD058();
    func_L01_004AB0E0();
    func_L01_004E20E8_004B8ED0();
    func_003CD350();
    *(u64 *)D_L01_001D7EA0 = 0;
    *(u64 *)(D_L01_001D7EA0 + 8) = 0;
    func_00384D88();
    if (D_L01_001D6698 != 0) {
        func_L01_004A9E58();
    } else {
        func_003A4288();
    }
    func_003D0B20();
    func_L01_0043AB98();
    if (D_00142660 > 0x5F5E0FF) {
        D_00142660 = 0x5F5E0FF;
    }
    func_00396568(1);
    i = 0;
    func_003AF498();
    func_L01_00478898();
    do {
        func_L01_004788D0(i);
        i++;
    } while (i <= 0);
    func_L01_0041AB50();
    func_003E55B8();
}

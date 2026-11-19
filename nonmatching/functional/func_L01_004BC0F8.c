/* functional: medium. Veldin vendor menu input state machine (T->w84: 1 = just pressed buy, 2 = choosing quantity, 4 = confirmed/cancelled), taking the "confirmed" and "quantity mode" bytes by pointer. Written from the PAL asm using the NTSC-U draft's shape only as a guide (PAL differs: threshold/price fields h84/h86 chosen by mode T->w5C, extra skip list 0x10/0x11/0x13/0x15/0x16 for buy-all in mode, callees func_L01_00511958 / 00419188 / 0044CD60 / 00419D48 / 0041BE20 / 0047C220(0xE4E1C0), money D_00142660). All branches, branch-likely delay slots and callee argument registers re-read against the asm; field names mine. */
extern s32 D_00142660;
extern u8 D_00142CA0[];
extern s32 D_001427F0[];
extern u8 *D_001D52FC_sda;
extern s32 D_L01_001E0F78;
extern s32 D_L01_001E0F88;
extern s32 D_L01_001E0F8C_sda;
extern s32 D_L01_001E0F90_sda;
extern s32 D_L01_001E0F94_sda;

extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_00381FF0(s32);
extern void func_L01_004BC0B8(s32);
extern void func_L01_004BAA20(s32);
extern void func_L01_004BF980(void);
extern s32 func_L01_004BA830(void);
extern s32 func_L01_00511958(s32, s32);
extern void func_L01_00419188(s32);
extern void func_L01_0044CD60(s32);
extern void func_L01_00419D48(s32);
extern void func_L01_0041BE20(s32);
extern void func_003935B0(s32, s32);
extern void func_L01_0047C220(s32);

void func_L01_004BC0F8(u8 *confirmed, u8 *quantity) {
    u8 *T = (u8 *)D_L01_002446C0;
    u8 *rec;
    u8 *pad;
    s32 sel;
    s32 id;
    s32 i;
    s32 n;
    s32 limit;
    s32 price;
    s32 left;
    s32 accepted;
    s32 c;
    s32 btn;

    if (*(s32 *)(T + 0x84) == 1) {
        sel = *(s32 *)(T + 0x80);
        if (T[sel * 0x14 + 0x152] == 1) {
            if (*(s32 *)(T + 0x754) <= 0) {
                func_003A52A0(2, 0x11, (void *)*(s32 *)(T + 0x28));
                return;
            }
            btn = *(s32 *)(D_001D52FC_sda + 0x1C4);
            accepted = 0;
            if (btn & 0x40) {
                for (i = 0; i < 0x9C; i++) {
                    if (D_00142CA0[i] == 0) {
                        continue;
                    }
                    rec = (u8 *)D_L01_002C5600 + D_001425C0[i] * 0xF0;
                    if (*(u16 *)(rec + 0x84) == 0) {
                        continue;
                    }
                    if (*(s32 *)(T + 0x5C) != 0) {
                        if ((u32)(i - 0x10) < 2 || i == 0x13 || i == 0x15 || i == 0x16) {
                            continue;
                        }
                    }
                    if (D_001427F0[i] < (s32)*(u16 *)(rec + 0x8A)) {
                        D_001427F0[i] = *(u16 *)(rec + 0x8A);
                    }
                }
                D_00142660 = D_00142660 - *(s32 *)(T + 0x754);
                D_L01_001E0F78 = 100;
                accepted = 1;
            } else if (btn & 0x10) {
                accepted = 1;
                func_003A52A0(0, 0x11, (void *)*(s32 *)(T + 0x28));
            }
            func_L01_004BC0B8((s32)func_00381FF0(0x17A));
            func_L01_004BAA20(0);
            func_003A52A0(7, 0x11, (void *)*(s32 *)(T + 0x28));
            if (accepted != 0) {
                *(s32 *)(T + 0x84) = 0;
                func_L01_004BF980();
            }
            return;
        }
        id = *(s32 *)(T + 0x140 + sel * 0x14);
        rec = (u8 *)D_L01_002C5600 + D_001425C0[id] * 0xF0;
        if (*(u16 *)(rec + 0x84) != 0) {
            D_L01_001E0F94_sda = D_00142660 / (s32)*(u16 *)(rec + 0x84);
        } else {
            D_L01_001E0F94_sda = 0;
        }
        id = *(s32 *)(T + 0x140 + *(s32 *)(T + 0x80) * 0x14);
        rec = (u8 *)D_L01_002C5600 + D_001425C0[id] * 0xF0;
        n = *(u16 *)(rec + 0x8A) - D_001427F0[id];
        if (n < D_L01_001E0F94_sda) {
            D_L01_001E0F94_sda = n;
        }
        *confirmed = 0;
        *quantity = 0;
        sel = *(s32 *)(T + 0x80);
        if (T[0x144 + sel * 0x14] == 1) {
            id = *(s32 *)(T + 0x140 + sel * 0x14);
            rec = (u8 *)D_L01_002C5600 + D_001425C0[id] * 0xF0;
            if (D_001427F0[id] >= (s32)*(u16 *)(rec + 0x8A)) {
                func_003A52A0(2, 0x11, (void *)*(s32 *)(T + 0x28));
            } else if (D_00142660 < (s32)*(u16 *)(rec + 0x84)) {
                func_003A52A0(2, 0x11, (void *)*(s32 *)(T + 0x28));
            } else {
                *quantity = 1;
            }
        } else {
            price = func_L01_004BA830();
            if (D_00142660 < price) {
                func_003A52A0(2, 0, (void *)*(s32 *)(T + 0x28));
            }
        }
        *(s32 *)(T + 0x84) = 2;
    } else if (*(s32 *)(T + 0x84) == 2) {
        pad = D_001D52FC_sda;
        if (*quantity == 1) {
            c = D_L01_001E0F88;
            if ((*(s32 *)(pad + 0x1C4) & 0x8000) || (c >= 16 && (c & 7) == 0) || c >= 48) {
                if (D_L01_001E0F94_sda >= 2) {
                    D_L01_001E0F94_sda = D_L01_001E0F94_sda - 1;
                    c = D_L01_001E0F88;
                    if ((c & 3) == 0 || c < 16) {
                        func_003A52A0(1, 0x11, (void *)*(s32 *)(T + 0x28));
                    }
                }
                pad = D_001D52FC_sda;
            }
            c = D_L01_001E0F8C_sda;
            if ((*(s32 *)(pad + 0x1C4) & 0x2000) || (c >= 16 && (c & 7) == 0) || c >= 48) {
                sel = *(s32 *)(T + 0x80);
                id = *(s32 *)(T + 0x140 + sel * 0x14);
                rec = (u8 *)D_L01_002C5600 + D_001425C0[id] * 0xF0;
                if (*(u16 *)(rec + 0x84) != 0) {
                    limit = D_00142660 / (s32)*(u16 *)(rec + 0x84);
                    n = *(u16 *)(rec + 0x8A) - D_001427F0[id];
                    if (!(n < limit)) {
                        n = limit;
                    }
                    if (D_L01_001E0F94_sda < n) {
                        D_L01_001E0F94_sda = D_L01_001E0F94_sda + 1;
                        c = D_L01_001E0F8C_sda;
                        if ((c & 3) == 0 || c < 16) {
                            func_003A52A0(1, 0x11, (void *)*(s32 *)(T + 0x28));
                        }
                    }
                }
                pad = D_001D52FC_sda;
            }
        }
        if ((*(s32 *)(pad + 0x1C4) & 0x10) && (D_L01_001E0F90_sda & 0x10) == 0) {
            *confirmed = 0;
            *(s32 *)(T + 0x84) = 4;
        } else if ((*(s32 *)(pad + 0x1C4) & 0x40) && (D_L01_001E0F90_sda & 0x40) == 0) {
            *confirmed = 1;
            *(s32 *)(T + 0x84) = 4;
        }
    } else if (*(s32 *)(T + 0x84) == 4) {
        if (*confirmed != 1) {
            func_003A52A0(0, 0x11, (void *)*(s32 *)(T + 0x28));
            *(s32 *)(T + 0x84) = 0;
            return;
        }
        sel = *(s32 *)(T + 0x80);
        id = *(s32 *)(T + 0x140 + sel * 0x14);
        rec = (u8 *)D_L01_002C5600 + D_001425C0[id] * 0xF0;
        if (T[0x144 + sel * 0x14] == 1) {
            price = *(u16 *)(rec + 0x84) * D_L01_001E0F94_sda;
        } else {
            price = func_L01_004BA830();
        }
        if (D_00142660 < price &&
            !(D_001427F0[id] < (s32)*(u16 *)(rec + 0x8A))) {
            func_003A52A0(0, 0x11, (void *)*(s32 *)(T + 0x28));
        } else {
            sel = *(s32 *)(T + 0x80);
            id = *(s32 *)(T + 0x140 + sel * 0x14);
            rec = (u8 *)D_L01_002C5600 + D_001425C0[id] * 0xF0;
            if (T[0x144 + sel * 0x14] == 1) {
                if (!(D_001427F0[id] < (s32)*(u16 *)(rec + 0x8A))) {
                    func_003A52A0(0, 0x11, (void *)*(s32 *)(T + 0x28));
                } else {
                    if (*(s32 *)(T + 0x5C) != 0) {
                        price = *(u16 *)(rec + 0x86);
                    } else {
                        price = *(u16 *)(rec + 0x84);
                    }
                    if (D_00142660 < price * D_L01_001E0F94_sda) {
                        func_L01_004BC0B8((s32)func_00381FF0(0x17B));
                        func_003A52A0(0, 0x11, (void *)*(s32 *)(T + 0x28));
                    } else {
                        sel = *(s32 *)(T + 0x80);
                        id = *(s32 *)(T + 0x140 + sel * 0x14);
                        rec = (u8 *)D_L01_002C5600 + D_001425C0[id] * 0xF0;
                        if ((s32)*(u16 *)(rec + 0x8A) < D_001427F0[id]) {
                            D_001427F0[id] = *(u16 *)(rec + 0x8A);
                        }
                        left = D_L01_001E0F94_sda;
                        left = left - func_L01_00511958(*(s32 *)(T + 0x140 + *(s32 *)(T + 0x80) * 0x14), left);
                        id = *(s32 *)(T + 0x140 + *(s32 *)(T + 0x80) * 0x14);
                        rec = (u8 *)D_L01_002C5600 + D_001425C0[id] * 0xF0;
                        if (*(s32 *)(T + 0x5C) == 0) {
                            price = *(u16 *)(rec + 0x84);
                        } else {
                            price = *(u16 *)(rec + 0x86);
                        }
                        D_00142660 = D_00142660 - price * left;
                        func_L01_004BAA20(0);
                        func_L01_004BC0B8((s32)func_00381FF0(0x17A));
                        func_003A52A0(7, 0x11, (void *)*(s32 *)(T + 0x28));
                    }
                }
            } else {
                price = func_L01_004BA830();
                if (D_00142660 < price) {
                    func_L01_004BC0B8((s32)func_00381FF0(0x17B));
                    func_003A52A0(0, 0x11, (void *)*(s32 *)(T + 0x28));
                } else {
                    sel = *(s32 *)(T + 0x80);
                    id = *(s32 *)(T + 0x140 + sel * 0x14);
                    if (T[0x151 + sel * 0x14] == 0) {
                        func_L01_00419188(id);
                        func_L01_0044CD60(id);
                    }
                    *(s32 *)(T + 0x68) = id;
                    if (T[0x150 + *(s32 *)(T + 0x80) * 0x14] != 0) {
                        *(s32 *)(T + 0x774) = 1;
                    }
                    sel = *(s32 *)(T + 0x80);
                    if (T[0x151 + sel * 0x14] != 0) {
                        func_L01_00419D48(*(s32 *)(T + 0x140 + sel * 0x14));
                    }
                    func_L01_0041BE20(*(s32 *)(T + 0x68));
                    D_00142660 = D_00142660 - price;
                    func_L01_004BAA20(0);
                    if (*(s32 *)(T + 0x78) != -1) {
                        func_003935B0(*(s32 *)(T + 0x78), 0);
                    }
                    *(s32 *)(T + 0x78) = -1;
                    sel = *(s32 *)(T + 0x80);
                    if (T[0x144 + sel * 0x14] == 1) {
                        func_L01_0047C220(0xE4E1C0);
                    } else {
                        n = *(s32 *)(T + 0x740) - 1;
                        if (n < sel) {
                            *(s32 *)(T + 0x80) = n;
                        }
                    }
                    func_L01_004BC0B8((s32)func_00381FF0(0x17A));
                    func_003A52A0(7, 0x11, (void *)*(s32 *)(T + 0x28));
                }
            }
        }
        *(s32 *)(T + 0x84) = 0;
    }
}

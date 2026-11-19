/* functional: high. Veldin third vendor page (slot stride 0x10, cost at slot+0x144, item value at +0x148, list index at +0x14C) input state machine, same states as func_L01_004BCAE8 (1 check, 2 wait confirm/cancel, 3 perform) but affordability comes from func_L01_004526F8 and a purchase also: calls func_L01_005147A8 with the item value, clears the slot cost and the D_L01_002F1C20 row's +8 word, calls func_L01_004BB120, records the value in D_L01_001DABCC/D0 and D_L01_001DABC8, charges the cost (func_L01_004526A0), redraws (func_L01_004C4E60), re-seats the shared selection (func_L01_00425978(D_001426A0)), shows text 0x17A. Refusal shows 0x17B. Names mine, offsets from asm. */
extern u8 D_L01_002F1C20[];
extern u8 *D_001D52FC_sda;
extern s32 D_L01_001E0F90_sda;
extern u8 D_L01_001DABC8_sda;
extern s32 D_L01_001DABCC_sda;
extern s32 D_L01_001DABD0_sda;
extern s16 D_001426A0;

extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_00381FF0(s32);
extern void func_L01_004BC0B8(s32);
extern void func_L01_004BF980(void);
extern s32 func_L01_004526F8(void);
extern void func_L01_004526A0(s32);
extern void func_L01_005147A8(s32);
extern void func_L01_004BB120(u32);
extern void func_L01_004C4E60(void);
extern void func_L01_00425978(s32);
extern void func_003A2750(s32);

void func_L01_004BCD08(u8 *confirmed) {
    u8 *T = (u8 *)D_L01_002446C0;
    s32 sel = *(s32 *)(T + 0x80);
    s32 state = *(s32 *)(T + 0x84);
    s32 cost = *(s32 *)(T + sel * 0x10 + 0x144);
    s32 btn;
    s32 v;

    if (state == 1) {
        *confirmed = 0;
        if (func_L01_004526F8() < cost) {
            func_003A52A0(2, 0x11, (void *)*(s32 *)(T + 0x28));
            *(s32 *)(T + 0x84) = 0;
        } else {
            func_003A52A0(0, 0x11, (void *)*(s32 *)(T + 0x28));
            *(s32 *)(T + 0x84) = 2;
        }
        return;
    }
    if (state == 2) {
        btn = *(s32 *)(D_001D52FC_sda + 0x1C4);
        if ((btn & 0x10) && (D_L01_001E0F90_sda & 0x10) == 0) {
            *confirmed = 0;
            *(s32 *)(T + 0x84) = 3;
            return;
        }
        btn = *(s32 *)(D_001D52FC_sda + 0x1C4);
        if ((btn & 0x40) == 0) {
            return;
        }
        if (D_L01_001E0F90_sda & 0x40) {
            return;
        }
        *confirmed = 1;
        *(s32 *)(T + 0x84) = 3;
        return;
    }
    if (state != 3) {
        return;
    }
    if (*confirmed != 0) {
        if (func_L01_004526F8() < cost) {
            func_L01_004BC0B8((s32)func_00381FF0(0x17B));
            func_003A52A0(0, 0x11, (void *)*(s32 *)(T + 0x28));
        } else {
            func_L01_005147A8(*(s32 *)(T + *(s32 *)(T + 0x80) * 0x10 + 0x148));
            sel = *(s32 *)(T + 0x80);
            v = *(s32 *)(T + sel * 0x10 + 0x14C);
            *(s32 *)(T + sel * 0x10 + 0x144) = 0;
            *(s32 *)(D_L01_002F1C20 + v * 0x10 + 8) = 0;
            func_L01_004BB120(*(s32 *)(T + *(s32 *)(T + 0x80) * 0x10 + 0x148));
            sel = *(s32 *)(T + 0x80);
            D_L01_001DABC8_sda = 1;
            D_L01_001DABCC_sda = *(s32 *)(T + sel * 0x10 + 0x148);
            func_003A52A0(7, 0x11, (void *)*(s32 *)(T + 0x28));
            func_L01_004526A0(cost);
            sel = *(s32 *)(T + 0x80);
            D_L01_001DABD0_sda = *(s32 *)(T + sel * 0x10 + 0x148);
            func_L01_004C4E60();
            if (D_L01_001DABD0_sda == -1) {
                func_L01_005147A8(0);
            } else {
                func_L01_005147A8(*(s32 *)(T + *(s32 *)(T + 0x80) * 0x10 + 0x148));
            }
            func_L01_00425978(D_001426A0);
            func_003A2750(1);
            func_L01_004BC0B8((s32)func_00381FF0(0x17A));
            func_003A52A0(7, 0x11, (void *)*(s32 *)(T + 0x28));
        }
    } else {
        func_003A52A0(0, 0x11, (void *)*(s32 *)(T + 0x28));
    }
    *(s32 *)(T + 0x84) = 0;
    func_L01_004BF980();
}

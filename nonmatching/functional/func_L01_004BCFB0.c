/* functional: high. Veldin fourth vendor page (slot stride 0x24, cost at slot+0x144, record word at +0x150, "locked" flag byte at +0x160) input state machine, states 1 (check: too poor or locked refuses with sound 2) / 2 (wait confirm or cancel) / 3 (perform: set T+0x76C, charge the cost, copy T+0x4C to D_001D54D0, call func_L01_00435FF0 with the record word, rebuild the list with func_L01_004BB330, clamp the cursor, sound 7). Names mine, offsets from asm. */
extern s32 D_00142660;
extern u8 *D_001D52FC_sda;
extern s32 D_L01_001E0F90_sda;
extern s32 D_001D54D0_sda;

extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004BF980(void);
extern void func_L01_00435FF0(s32);
extern void func_L01_004BB330(void);

void func_L01_004BCFB0(u8 *confirmed) {
    u8 *T = (u8 *)D_L01_002446C0;
    s32 sel = *(s32 *)(T + 0x80);
    s32 state = *(s32 *)(T + 0x84);
    u8 *slot = T + sel * 0x24;
    s32 cost = *(s32 *)(slot + 0x144);
    s32 btn;
    s32 cnt;

    if (state == 1) {
        *confirmed = 0;
        if (D_00142660 < cost || slot[0x160] != 0) {
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
        if (D_00142660 < cost) {
            func_003A52A0(0, 0x11, (void *)*(s32 *)(T + 0x28));
        } else {
            *(s32 *)(T + 0x76C) = 1;
            D_00142660 = D_00142660 - cost;
            D_001D54D0_sda = *(s32 *)(T + 0x4C);
            func_L01_00435FF0(*(s32 *)(slot + 0x150));
            func_L01_004BB330();
            cnt = *(s32 *)(T + 0x740);
            if (cnt < *(s32 *)(T + 0x80)) {
                *(s32 *)(T + 0x80) = cnt;
            }
            func_003A52A0(7, 0x11, (void *)*(s32 *)(T + 0x28));
        }
    } else {
        func_003A52A0(0, 0x11, (void *)*(s32 *)(T + 0x28));
    }
    *(s32 *)(T + 0x84) = 0;
    func_L01_004BF980();
}

/* functional: high. Veldin second vendor page (single-purchase list, slot stride 0x10, cost at slot+0x144) input state machine, T->w84: 1 = check money, 2 = wait for confirm/cancel, 3 = perform. On confirm it sets D_L01_001DABC8 and D_L01_001DABD0 (the bought item's value), deducts the cost, shows text 0x17A, rebuilds the list (func_L01_004BD170) and calls func_L01_004BF980; refuses with text 0x17B when too poor or D_L01_001DABD4 == 4. Names mine, offsets from asm. */
extern s32 D_00142660;
extern u8 *D_001D52FC_sda;
extern s32 D_L01_001E0F90_sda;
extern u8 D_L01_001DABC8_sda;
extern s32 D_L01_001DABD0_sda;
extern s32 D_L01_001DABD4_sda;

extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_00381FF0(s32);
extern void func_L01_004BC0B8(s32);
extern void func_L01_004BD170(void);
extern void func_L01_004BF980(void);

void func_L01_004BCAE8(u8 *confirmed) {
    u8 *T = (u8 *)D_L01_002446C0;
    s32 sel = *(s32 *)(T + 0x80);
    s32 state = *(s32 *)(T + 0x84);
    s32 cost = *(s32 *)(T + sel * 0x10 + 0x144);
    s32 btn;

    if (state == 1) {
        *confirmed = 0;
        if (D_00142660 < cost) {
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
        if (D_00142660 < cost || D_L01_001DABD4_sda == 4) {
            func_L01_004BC0B8((s32)func_00381FF0(0x17B));
            func_003A52A0(0, 0x11, (void *)*(s32 *)(T + 0x28));
        } else {
            D_L01_001DABC8_sda = 1;
            D_L01_001DABD0_sda = *(s32 *)(T + sel * 0x10 + 0x148);
            func_003A52A0(7, 0x11, (void *)*(s32 *)(T + 0x28));
            D_00142660 = D_00142660 - cost;
            func_L01_004BC0B8((s32)func_00381FF0(0x17A));
            func_003A52A0(7, 0x11, (void *)*(s32 *)(T + 0x28));
            func_L01_004BD170();
        }
    } else {
        func_003A52A0(0, 0x11, (void *)*(s32 *)(T + 0x28));
    }
    *(s32 *)(T + 0x84) = 0;
    func_L01_004BF980();
}

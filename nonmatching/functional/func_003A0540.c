/* functional: high. Starts a DMA channel transfer on the channel at 0x1000D400 (SIF/SPR group): writes MADR-like fields 0x10=a0, 0x20=a1, 0x80=a2, then CHCR=0x100 last. Register block declared as a named volatile (hardware), no address literal. Stores happen in this order as retail. */
extern volatile u32 D_1000D400[];

void func_003A0540(u32 a0, u32 a1, u32 a2)
{
    D_1000D400[0x80 / 4] = a2;
    D_1000D400[0x20 / 4] = a1;
    D_1000D400[0x10 / 4] = a0;
    D_1000D400[0] = 0x100;
}

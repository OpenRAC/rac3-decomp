/* Near miss, ported from rac4-decomp's func_004F3800 (cross-game near pair). NEAR: shared $gp function; retail reads the counter via $gp (hoisted into the beqz delay slot) on one path and via lui/lw 0x24112C on the other, stores via lui $at; a single declaration cannot produce both (GP-SLOT-like); 3 wordings tried */
typedef struct {
    u16 a, count;
} State_0060B4C8;
extern State_0060B4C8 D_001FC340;
extern s32 D_00241128, D_0024112C;
extern s32 (*D_001DA108_sda)(s32);
extern void (*D_001DA10C_sda)(s32);
extern u32 D_001DA124_sda;
extern void func_005C46E0(void);

s32 func_L39_0060B4C8(s32 value)
{
    s32 result;
    D_00241128 = 6;
    ((State_0060B4C8 *)((u8 *)&D_001FC340 + 0x20))->count++;
    result = D_001DA108_sda(value);
    if (D_001DA124_sda & 16)
        func_005C46E0();
    if (D_001DA10C_sda)
        D_001DA10C_sda(value);
    D_0024112C++;
    return result;
}

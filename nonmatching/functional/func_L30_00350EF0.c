/* functional: high. Same calls and stores in retail order; only branch scheduling differs. */
__asm__(".extern D_L30_001DD86C, 4");
extern s32 D_L30_001DD86C;
extern void func_L30_00352208(void *);
extern void func_L30_00350FA8(void *);
typedef struct { u8 pad[0x1C]; s32 x1C; } V_350EF0;
typedef struct { u8 pad[0x20]; u8 x20; u8 pad21[0x68 - 0x21]; V_350EF0 *x68; } O_350EF0;
void func_L30_00350EF0(O_350EF0 *self) {
    V_350EF0 *v = self->x68;
    func_0038D098((f32)(D_L30_001DF2C0 % D_L30_001DD86C) / (f32)D_L30_001DD86C * 6.2831855f);
    if (self->x20 == 0) {
        func_L30_00350FA8(self);
        func_L01_004450F0(self, 1, -1);
    }
    if (self->x20 == 1) {
        v->x1C = v->x1C + 1;
        func_L30_00352208(self);
    }
}

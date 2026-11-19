/* functional: high. EXACT at level_07 (MATCH) with the file's flags incl. @ps2as; taken from the nonmatching/levels draft, checked here. Only 1 place. */
extern void func_L07_003AF600(void *);
extern void func_L07_003AF678(u8 *);
extern s32 func_L07_003AF758(u8 *);
extern void func_L07_003AF7F8(u8 *);
extern void func_L07_003AF7B8();
extern void func_L07_003AF920(u8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_004AA760(s32, void *);
void func_L07_003AF398(u8 *self) {
    u8 *p;
    func_L07_003AF600(self);
    func_L07_003AF678(self);
    p = *(u8 **)(self + 0x68);
    switch (self[0x20]) {
    case 1:
        if (func_L07_003AF758(self)) {
            func_003A52A0(1, 4, self);
            func_L01_004450F0(self, 2, -1);
        }
        break;
    case 2:
        *(f32 *)(p + 0xD4) += 0.010053097f;
        if (*(f32 *)(p + 0xD4) > 0.25132743f) {
            *(f32 *)(p + 0xD4) = 0.25132743f;
            func_L01_004450F0(self, 3, -1);
        }
        func_L07_003AF7F8(self);
        ((void (*)(void *, f32))func_L07_003AF7B8)(self, *(f32 *)(p + 0xD4));
        if (!func_L07_003AF758(self)) func_L01_004450F0(self, 4, -1);
        break;
    case 3:
        if (func_L01_004561B8(self)) *(s16 *)(p + 0xE8) = 250;
        if (++*(u16 *)(self + 0x96) >= 6) {
            func_003A52A0(0, 0, self);
            func_L07_003AF920(self);
            *(u16 *)(self + 0x96) = 0;
        }
        func_L07_003AF7F8(self);
        ((void (*)(void *, f32))func_L07_003AF7B8)(self, *(f32 *)(p + 0xD4));
        if (func_0038CB00(p + 0xE8) || !func_L07_003AF758(self))
            func_L01_004450F0(self, 4, -1);
        break;
    case 4:
        *(f32 *)(p + 0xD4) -= 0.010053097f;
        if (*(f32 *)(p + 0xD4) <= 0.0f) {
            *(f32 *)(p + 0xD4) = 0.0f;
            if (func_L07_003AF758(self)) func_L01_004450F0(self, 5, -1);
            else {
                func_L01_004AA760(1, self);
                func_L01_004450F0(self, 1, -1);
            }
        }
        ((void (*)(void *, f32))func_L07_003AF7B8)(self, *(f32 *)(p + 0xD4));
        break;
    case 5:
        if (func_L01_004561B8(self)) *(s16 *)(p + 0xE8) = 100;
        if (!func_L07_003AF758(self)) {
            func_L01_004AA760(1, self);
            func_L01_004450F0(self, 1, -1);
        } else if (func_0038CB00(p + 0xE8)) func_L01_004450F0(self, 2, -1);
        break;
    }
}

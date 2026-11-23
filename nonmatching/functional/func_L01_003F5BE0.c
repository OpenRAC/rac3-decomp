/* functional: high. 29 instruction positions differ at L01 (scheduling only); from the in-tree PAL draft nonmatching/levels/func_L01_003F5BE0.c with every constant, stride and offset re-checked against the PAL assembly. Needs the file context (qzero, u128_003F5AC0 from L01_003F5A78.c prelude). */
extern u8 *D_L01_001DF8C0[1];
extern u8 D_L01_001E2A40[];
extern u8 D_L01_001DF890[];
extern u8 D_L01_001E2FD0[];
extern s32 D_L01_001DF808;
extern u8 *D_L01_001DF804;
extern s32 D_L01_001DF800[];
__asm__(".extern D_001D5FE8_sda, 8");
extern f32 D_001D5FE8_sda[2];
void func_L01_003F5BE0(void) {
    extern void func_L01_003F3068(s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_003F2A00(s32);
    extern s32 func_L01_003F5A78(s32);
    extern void func_L01_003F5AC0(s32, s32);
    s32 i, player;
    {
        s32 k = 15;
        u8 **slot = D_L01_001DF8C0 + 15;
        for (; k >= 0; k--) { *slot-- = 0; }
    }
    player = 0;
    do {
        u8 *camera = D_L01_001E2A40 + player * 0x460;
        u8 *follow = camera + 0x60;

        *(s32 *)(camera + 0x450) = 0;
        *(s32 *)(camera + 0x454) = 0;
        func_L01_003F3068(player);
        qzero(camera + 0x410);
        *(s32 *)(camera + 0x54) = 0;
        *(s16 *)(camera + 0x2A0) = 0;
        func_0038CF68(camera + 0x80, *(u8 **)(camera + 0x240) + 0xE0, 1.0f);
        { u128_003F5AC0 pos = *(u128_003F5AC0 *)(camera + 0x190);
        qzero(camera + 0xB0);
        *(u128_003F5AC0 *)(camera + 0xC0) = pos; }
        {
        u8 *active = (u8 *)(player * 0x30 + (s32)D_L01_001DF890);
        u8 *entry = (u8 *)(player * 0x2100 + (s32)D_L01_001E2FD0);
        *(u128_003F5AC0 *)(camera + 0xA0) = *(u128_003F5AC0 *)(camera + 0x90) = *(u128_003F5AC0 *)(camera + 0x80);
        *(s32 *)(follow + 0xC4) = 0;
        *(s32 *)(follow + 0xE4) = 0;
        *(s32 *)(follow + 0xC0) = 0;
        *(s32 *)(follow + 0xCC) = 0;
        *(s32 *)(follow + 0xE8) = 0;
        D_001D5FE8_sda[player] = 0.85f;
        *(f32 *)(follow + 0xAC) = *(f32 *)(follow + 0xB0) = *(f32 *)(follow + 0xB4) = *(f32 *)(follow + 0xB8) = *(f32 *)(follow + 0xBC) = *(f32 *)(camera + 0x1A8);
        for (i = 47; i >= 0; i--) {
            *(s16 *)(entry + 0x8E) = 0;
            *(s32 *)(entry + 0x94) = player;
            *active++ = 0;
            entry += 0xB0;
        }
        }
        func_L01_003F2A00(player);
        i = 0;
        if (D_L01_001DF808 > 0) {
        u8 *active = (u8 *)(player * 0x30 + (s32)D_L01_001DF890);
        u8 *entry = (u8 *)(player * 0x2100 + (s32)D_L01_001E2FD0);
        do {
            u8 *row = (u8 *)(i * 0x20 + (s32)D_L01_001DF804);
            u8 *object = *(u8 **)(row + 0x1C);
            *(s16 *)(entry + 0x84) = i;
            *(u8 **)(object + 4) = entry;
            *(s16 *)(entry + 0x8E) = 0;
            entry[0x89] = 0;
            *(s16 *)(entry + 0x8A) = 0;
            *(s16 *)(entry + 0x82) = -1;
            *(s16 *)(entry + 0x80) = -1;
            entry[0x7D] = 0;
            *(s16 *)(entry + 0x7E) = 0;
            *(f32 *)(entry + 0x78) = -1.0f;
            entry[0x7C] = object[0x1C];
            *(s32 *)(entry + 0x74) = object[0x1F];
            {
                u16 id = *(u16 *)(row + 0xC);
                *active++ = 1;
                *(s16 *)(entry + 0x86) = id;
                *(s16 *)(entry + 0x8C) = func_L01_003F5A78((s16)id);
            }
            entry += 0xB0;
            i++;
        } while (i < D_L01_001DF808);
        }
        func_L01_003F5AC0(player, 1);
        *(s16 *)(camera + 0x2A0) = 0;
        {
        u8 *tail = camera + 0x3F0;
        *(s32 *)(tail + 0xC) = 0;
        *(s32 *)(tail + 4) = 0;
        *(s32 *)(camera + 0x3F0) = 0;
        *(s32 *)(tail + 0x10) = 0;
        }
        D_L01_001DF800[player] = 0;
        player++;
    } while (player <= 0);
}

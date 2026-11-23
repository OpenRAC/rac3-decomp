/* functional: high. Draft (Codex near miss) verified against all of the asm; VU0 vadd.xyz as plain float adds with w taken from the velocity quad (pos) or the position (temp) as retail stores. */
typedef struct { u8 pad[0x2F]; u8 player; } Hero_0035C098;
typedef struct { u8 pad; u8 flag; u8 rest[0xEE]; } Row_0035C098;
typedef struct { u8 pad[0x18]; u8 *hit; s128 position; s128 normal; s128 extra; } Contact_0035C098;
typedef struct { s128 data; s32 gun; u8 pad[4]; u8 kind, flag; u16 cls; u8 tail[0x14]; } Damage_0035C098;
extern Hero_0035C098 D_001425C0;
extern Row_0035C098 D_L01_002C5600[];
extern Contact_0035C098 D_L01_001EAA00;
extern S_38C110v D_L01_001EAA20;
void func_L01_0035C098(u8 *m) {
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_0035C6B0(char *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern s32 func_003C4B50(void *);
    extern void func_L01_0034C9F0(void *, s32, void *);
    extern void func_003D4D00(void *, s32, void *, void *, f32);
    extern void func_L01_0035CAD0(void *);
    extern void func_L01_0040E790(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32,
        f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
        s32, s32, s32, s32, s32, s32, s32, s32);
    extern s32 func_0038DC20(void *, f32);
    extern void func_L01_00404A10(void (*)(u8 *), void *);
    extern void func_L01_0035C8D0(u8 *);
    extern void func_L01_0035D358(void *, void *, void *);
    extern void func_L01_0035CFC8(void *, void *, void *);
    S_38C110v old, temp;
    union { Damage_0035C098 damage; S_38C110v current; } shared;
    N60Bullet_0035BF48 *v = *(N60Bullet_0035BF48 **)(m + 0x68);
    u8 *hit;
    if (func_L01_004CB2D8()) func_L01_004CAB30(m + 0x10, m + 0x10);
    switch (m[0x20]) {
    case 0:
        *(s128 *)&old = *(s128 *)(m + 0x10);
        func_L01_004C8688(v->shadow, v, 0);
        *(f32 *)(m + 0x10) += *(f32 *)v; *(f32 *)(m + 0x14) += *(f32 *)((u8 *)v + 4); *(f32 *)(m + 0x18) += *(f32 *)((u8 *)v + 8);
        *(f32 *)(m + 0x1C) = *(f32 *)((u8 *)v + 12); /* vadd.xyz stores the velocity quad's w */
        if (*(f32 *)(m+0x10) < 2.0f || *(f32 *)(m+0x10) > 1021.0f ||
            *(f32 *)(m+0x14) < 2.0f || *(f32 *)(m+0x14) > 1021.0f ||
            *(f32 *)(m+0x18) < 2.0f || *(f32 *)(m+0x18) > 1021.0f) func_L01_0035C6B0((char *)m);
        v->bounces++;
        if (func_003D3CB0(&old, m+0x10, 0, m, 0)) {
            if (D_L01_002C5600[D_001425C0.player].flag == 0) {
                m[0x20] = 1;
                *(s128 *)(m+0x10) = *(s128 *)&D_L01_001EAA20;
                *(s128 *)&temp = v->velocity;
                func_0038CE20(&temp, &temp, 0.5f);
                temp.w = 5627.9248046875f;
                func_L01_00446760(&shared.damage, m, v->life, &temp, v->damage);
                shared.damage.gun = v->gun;
                shared.damage.flag = 1;
                shared.damage.cls = *(u16 *)(m+0xAA);
                shared.damage.kind = 0;
                hit = D_L01_001EAA00.hit;
                if (hit && (*(s16 *)(hit+0xAA) == 0x18BE || *(s16 *)(hit+0xAA) == 0 || hit == (u8 *)v->gun)) goto contact_done;
                if (hit) goto damage_full;
                func_003D4D00(&D_L01_001EAA20, 0, m, &shared.damage, 0.6f);
                goto collision_end;
            } else {
                m[0x20] = 1;
                *(s128 *)&temp = v->velocity;
                func_0038CE20(&temp, &temp, 0.5f);
                temp.w = 5627.9248046875f;
                func_L01_00446760(&shared.damage, m, v->life, &temp, v->damage);
                shared.damage.gun = v->gun;
                shared.damage.flag = 1;
                shared.damage.cls = *(u16 *)(m+0xAA);
                shared.damage.kind = 0;
                hit = D_L01_001EAA00.hit;
                if (hit) {
                    if (*(s16 *)(hit+0xAA) == 0x18BE || *(s16 *)(hit+0xAA) == 0 || hit == (u8 *)v->gun) goto contact_done;
                    if ((*(u8 **)(hit+0x24) && (*(u8 **)(hit+0x24))[0x46] == 5) || func_003C4B50(hit) ||
                        (D_L01_001EAA00.hit && *(u8 **)(D_L01_001EAA00.hit+0x24) && (*(u8 **)(D_L01_001EAA00.hit+0x24))[0x46] == 0x16) ||
                        *(s16 *)(D_L01_001EAA00.hit+0xAA) == 0x61C) {
                        func_L01_0034C9F0(D_L01_001EAA00.hit, 0x2F, m);
                        goto damage_full;
                    }
                }
                goto bounce;
            }
        damage_full:
            func_003D4D00(&D_L01_001EAA20, 0, m, &shared.damage, 1.0f);
            goto collision_end;
        bounce:
            *(s128 *)(m+0x10) = *(s128 *)&D_L01_001EAA20;
            func_L01_0035CAD0(m+0x10);
            func_L01_0040E790(v, v, (u8 *)&D_L01_001EAA20+0x20);
        contact_done:
            *(f32 *)(m + 0x10) += *(f32 *)v; *(f32 *)(m + 0x14) += *(f32 *)((u8 *)v + 4); *(f32 *)(m + 0x18) += *(f32 *)((u8 *)v + 8);
            *(f32 *)(m + 0x1C) = *(f32 *)((u8 *)v + 12);
            m[0x20] = 0;
        }
    collision_end:
        if (D_L01_002C5600[D_001425C0.player].flag == 0 && v->bounces >= 26) {
            func_L01_0035CAD0(m+0x10);
            func_L01_0035C6B0((char *)m);
        }
        if (D_L01_002C5600[D_001425C0.player].flag != 0 && v->bounces >= 38) {
            func_L01_0035CAD0(m+0x10);
            func_L01_0035C6B0((char *)m);
        }
        break;
    case 1:
        func_0038CF68(v, v, -0.1f);
        temp.x = *(f32 *)(m + 0x10) + *(f32 *)v; temp.y = *(f32 *)(m + 0x14) + *(f32 *)((u8 *)v + 4); temp.z = *(f32 *)(m + 0x18) + *(f32 *)((u8 *)v + 8);
        temp.w = *(f32 *)(m + 0x1C);
        if (D_L01_002C5600[D_001425C0.player].flag == 0) {
            func_L01_003303B8(&temp,0,5,2,2,2,0,0,0.14f,0.0f,0.0f,0.0f,
                0,1,0,0,1,0,0x01010000,0,0x00399EF7,0x93F7,0x00409FFF,0x90FF,
                0x9FFF,0x003094FF,0x7F205F7F,0x28005F7F,0x0030DFFF,1);
        }
        func_L01_0035C6B0((char *)m);
        break;
    }
    *(s128 *)&temp = *(s128 *)(m+0x10);
    temp.w = 0.5f;
    if (func_0038DC20(&temp, 96.0f) > 0) {
        func_L01_00404A10(func_L01_0035C8D0, m);
        if (v->tracer) {
            *(s128 *)&shared.current = *(s128 *)(m+0x10);
            func_L01_0035D358(m, &shared.current, &old);
        } else {
            *(s128 *)&shared.current = *(s128 *)(m+0x10);
            func_L01_0035CFC8(m, &shared.current, &old);
        }
    }
}

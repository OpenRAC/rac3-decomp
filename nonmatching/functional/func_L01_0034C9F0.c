/* functional: medium. Near-miss draft (compiles under file flags); 259 diff words; row table alias D_L01_00282220_0034C9F0 declared later in file; description inferred from draft and callee inventory, not every branch re-read */
/* localdecomp:start func_L01_0034C9F0 */
typedef struct { u8 enabled, kind; u8 pad2[0x46]; s16 alias; u8 pad4A[0x22]; f32 damage; u8 pad70[0x80]; } Weapon_0034C9F0;
extern Weapon_0034C9F0 D_L01_002C5600[];
extern u8 D_00142A60[];
extern u8 D_001425C0[];
extern s32 D_001A5E08[];
extern S_27F600 D_L01_0027F580[];
typedef struct { f32 damage, arc_damage; s32 seconds; f32 interval; } Row_0034C9F0;
extern Row_0034C9F0 D_L01_00282220_0034C9F0[][204];
extern s32 D_L01_001DD3D8;
__asm__(".extern D_L01_001DD3D8, 4");
typedef struct {
    s128 position;
    u8 pad10[8];
    u8 kind, active;
    u16 class_id;
    u8 pad1C[4];
    s32 enabled;
    u8 pad24[12];
} Hit_0034C9F0;
static __inline__ u8 active_0034C9F0(s32 id, s32 kind) {
    Weapon_0034C9F0 *entry = &D_L01_002C5600[D_001425C0[id]];
    if (entry->enabled != 0) { if (entry->kind == kind) return 1; }
    return 0;
}
s32 func_L01_0034C9F0(u8 *object, s32 id, s32 owner) {
    extern f32 *func_00382348(u8 *);
    extern s32 func_L01_0034C990(s32);
    extern void func_003C6FB0(u8 *, s32 *, s32 *, s32 *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00446760(void *, s32, s32, void *, f32);
    extern void func_L01_00446978(u8 *, void *);
    f32 direction[4] __attribute__((aligned(16)));
    Hit_0034C9F0 hit;
    s32 red, green, blue;
    s32 bank = 0;
    s32 resolved = D_L01_002C5600[id].alias;
    s32 result = 1;
    f32 *health;
    s32 i;
    u8 *slot;
    Row_0034C9F0 *row;
    s32 override;
    if (resolved == 0) resolved = id;
    if (!(((unsigned long)D_00142A60[resolved] >> 1) & 1)) return 1;
    if (active_0034C9F0(resolved, 2)) bank = 1;
    else if (active_0034C9F0(resolved, 3)) bank = 1;
    if ((*(u8 **)(object + 0x24))[0x46] != 5 || !(*(u16 *)(object + 0x34) & 0x1000)) return 1;
    if (*(s8 *)(object + 0x20) < 0 || *(s32 *)(object + 0x98) == 0) return 1;
    health = func_00382348(object);
    if (health == 0) return 1;
    if (*health <= 0.0f) return 1;
    if (func_L01_0034C990((s32)object) != -1) return 1;
    row = &D_L01_00282220_0034C9F0[bank][id];
    override = D_001A5E08[0];
    for (i = 0; i < 30; i++) {
        if (D_L01_0027F580[i].x18 == 0) {
            u8 *p;
            s32 have_color;
            slot = (u8 *)&D_L01_0027F580[i];
            *(s32 *)(slot + 0) = row->seconds * 50;
            *(f32 *)(slot + 0x10) = row->arc_damage;
            if (override == 0x27) *(f32 *)(slot + 0x10) = D_L01_002C5600[D_001425C0[0x27]].damage * 0.25f;
            else if (override == 0x77) *(f32 *)(slot + 0x10) = D_L01_002C5600[D_001425C0[0x77]].damage * 0.25f;
            else if (override == 0x2F) *(f32 *)(slot + 0x10) = D_L01_002C5600[D_001425C0[0x2F]].damage * 0.25f;
            else if (override == 0x15) *(f32 *)(slot + 0x10) = D_L01_002C5600[D_001425C0[0x15]].damage * 0.25f;
            else if (override == 0x47) *(f32 *)(slot + 0x10) = D_L01_002C5600[D_001425C0[0x47]].damage * 0.25f;
            *(f32 *)(slot + 0x14) = (row->interval * 5.0f + 2.0f) / 6.0f;
            *(u8 **)(slot + 0x18) = object;
            *(s32 *)(slot + 0x20) = owner;
            *(s32 *)(slot + 0x1C) = 0;
            health = func_00382348(object);
            *health -= row->damage;
            have_color = 0;
            p = *(u8 **)(slot + 0x18);
            if (*(u16 *)(p + 0x34) & 0x20) {
                p = *(u8 **)(*(u8 **)(p + 0x68) + 0x10);
                if (p != 0 && *(s16 *)p != 0) {
                    red = p[4]; green = p[5]; blue = p[6];
                    have_color = 1;
                }
            }
            if (!have_color) func_003C6FB0(*(u8 **)(slot + 0x18), &red, &green, &blue);
            *(s32 *)(slot + 0xC) = 0;
            *(s32 *)(slot + 8) = 0xFF0000;
            *(s32 *)(slot + 0x24) = 1;
            *(s32 *)(slot + 4) = (blue << 16) + (green << 8) + red;
            result = 0;
            if (*health <= *(f32 *)(slot + 0xC) && D_L01_001DD3D8 != 0) {
                func_0038CE20(direction, (f32 *)(*(u8 **)(slot + 0x18) + 0xC0), -1.0f);
                func_0038CF68(&hit, &hit, 0.0020000000949949026f);
                *(s32 *)((u8 *)D_L01_001DD3D8 + 0xB8) = *(s32 *)(slot + 0x20);
                func_L01_00446760(&hit, *(s32 *)(slot + 0x20), 0x410000, direction, 0.0010000000474974513f);
                hit.position = *(s128 *)direction;
                ((f32 *)&hit)[3] = 5627.9248046875f;
                hit.active = 1;
                hit.kind = 5;
                hit.class_id = *(u16 *)(*(u8 **)(slot + 0x18) + 0xAA);
                hit.enabled = 1;
                func_L01_00446978(*(u8 **)(slot + 0x18), &hit);
                *(s32 *)(slot + 0x18) = 0;
            }
            break;
        }
    }
    return result;
}
/* localdecomp:end func_L01_0034C9F0 */

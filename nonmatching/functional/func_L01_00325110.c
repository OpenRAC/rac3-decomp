/* functional: high. 2 words differ from retail (register choice only); draft from Codex wave 6. */
typedef struct V_00325110 {
    s32 key;
    u8 pad4[0x4F];
    u8 index;
    u8 pad54[0x14];
    u8 *prev;
    u8 *next;
} V_00325110;
extern u8 *D_L01_001E001C;
extern s16 *D_L01_0021DE20[];
extern s32 D_001E0058_sda;
void func_L01_00325110(void *unused, u8 *list) {
    extern s32 func_L01_003250A8(s32 *a0);
    V_00325110 *v;
    s16 *p;
    s16 *reset;
    u8 *obj;
    V_00325110 *cur;
    u8 *cursor;
    s32 count;
    s32 id;
    *(s32 *)(list + 32) = 0;
    *(u8 **)(list + 4) = 0;
    reset = D_L01_0021DE20[*(s32 *)(list + 28)];
    while (((u8)(id = *(s32 *)(list + 28)) != 255) &&
           D_001E0058_sda >= id && reset &&
           (reset[-1] >= 0 || reset == D_L01_0021DE20[id])) {
        obj = D_L01_001E001C + (((u16)*reset & 0x7FFF) << 8);
        if (!obj) break;
        v = *(V_00325110 **)(obj + 104);
        v->index = 255;
        v->prev = 0;
        v->next = 0;
        (*(s32 *)(list + 32))++;
        reset++;
    }
    p = D_L01_0021DE20[*(s32 *)(list + 28)];
    count = 0;
    cursor = 0;
    cur = 0;
    while (((u8)(id = *(s32 *)(list + 28)) != 255) &&
           D_001E0058_sda >= id && p &&
           (p[-1] >= 0 || p == D_L01_0021DE20[id])) {
        obj = D_L01_001E001C + (((u16)*p & 0x7FFF) << 8);
        if (!obj) break;
        v = *(V_00325110 **)(obj + 104);
        v->index = func_L01_003250A8((s32 *)v);
        if (count == 0) {
            cursor = obj;
            *(u8 **)(list + 4) = cursor;
            count = 1;
            cur = *(V_00325110 **)(cursor + 104);
        } else {
            while (v->key < cur->key && cur->prev) {
                cursor = cur->prev;
                cur = *(V_00325110 **)(cursor + 104);
            }
            if (!cur->prev && v->key < cur->key) {
                cur->prev = obj;
                v->next = cursor;
                *(u8 **)(list + 4) = obj;
            } else {
                while (cur->key < v->key && cur->next) {
                    cursor = cur->next;
                    cur = *(V_00325110 **)(cursor + 104);
                }
                if (!cur->next && cur->key < v->key) {
                    cur->next = obj;
                    v->prev = cursor;
                } else if (v->key < cur->key) {
                    v->prev = cur->prev;
                    v->next = cursor;
                    if (cur->prev) {
                        (*(V_00325110 **)(cur->prev + 104))->next = obj;
                    }
                    cur->prev = obj;
                } else {
                    v->prev = cursor;
                    v->next = cur->next;
                    if (cur->next) {
                        (*(V_00325110 **)(cur->prev + 104))->prev = obj;
                    }
                    cur->next = obj;
                }
            }
            count++;
        }
        p++;
    }
}

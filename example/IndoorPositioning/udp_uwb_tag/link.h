#include <Arduino.h>

struct MyLink
{
    uint16_t anchor_addr;
    float range[3];
    float dbm;
    struct MyLink *next;
};

struct MyLink *init_link();
void add_link(struct MyLink *p, uint16_t addr);
struct MyLink *find_link(struct MyLink *p, uint16_t addr);
void fresh_link(struct MyLink *p, uint16_t addr, float range, float dbm);
void print_link(struct MyLink *p);
void delete_link(struct MyLink *p, uint16_t addr);
void make_link_json(struct MyLink *p,String *s);
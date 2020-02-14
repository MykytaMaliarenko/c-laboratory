//
// Created by nam62 on 04.02.2020.
//

#ifndef INC_1_MENU_H
#define INC_1_MENU_H

struct MenuOption
{
    char *name;
    void (*execute)();
};

void Start(struct MenuOption options[], int length);

#endif //INC_1_MENU_H

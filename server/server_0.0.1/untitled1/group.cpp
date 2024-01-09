#include "group.h"

group::group()
{

}

void group::insertUser(user* user)
{
    if(firstUser==nullptr)
    {
        firstUser = user;
        connect(firstUser, &user::signalsendMessage, this, &group::slotSendMsgFirtsUser);
    }
    else if(secondUser==nullptr)
    {
        secondUser = user;
        connect(secondUser, &user::signalsendMessage, this, &group::slotSendMsgSecondUser);
    }
    else return;//достигнуто максимальное количество игроков
}

void group::slotSendMsgFirtsUser()
{
    //Отправка во второй контроллер(+ возможно в будущем всем зрителям)
}

void group::slotSendMsgSecondUser()
{
    //Отправка во первый контроллер(+ возможно в будущем всем зрителям)
}

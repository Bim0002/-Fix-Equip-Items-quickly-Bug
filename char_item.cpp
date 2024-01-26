
- Find:

  case ITEM_PICK:
            // END_OF_MINING
            if (!item->IsEquipped())
                EquipItem(item);
            else
                UnequipItem(item);
            break; 

  change it :

  case ITEM_PICK:
        if( item->IsEquiped())
            if(GetQuestFlag(QUICK_CHANGE_BLOOK) && get_global_time() < GetQuestFlag(QUICK_CHANGE_BLOOK))
            {
                ChatPacket(CHAT_TYPE_INFO, "You Need to wait for %d" , (GetQuestFlag(QUICK_CHANGE_BLOOK) - get_global_time) % 60);
                return false;
            }
            EquipItem(item);
            SetQuestFlag("QUICK_CHANGE_BLOOK", get_global_time + 5);
        else
            UnequipItem(item);
        break;
        

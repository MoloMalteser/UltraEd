void _UER_ActorUpdate(Gfx **display_list, NUContData gamepads[4])
{
    for (int i = 0; i < vector_size(_UER_Actors); i++)
    {
        Actor *actor = vector_get(_UER_Actors, i);

        if (actor->parent == NULL) CActor_Draw(actor, display_list);

        if (actor->update != NULL) actor->update(actor);

        if (actor->input != NULL) actor->input(actor, gamepads);
    }

    for (int i = 0; i < vector_size(_UER_ActorsPendingRemoval); i++)
    {
        Actor *actorToRemove = vector_get(_UER_ActorsPendingRemoval, i);

        for (int j = 0; j < vector_size(_UER_Actors); j++)
        {
            Actor *actor = vector_get(_UER_Actors, j);

            if (actor->id != actorToRemove->id)
                continue;

            vector_remove_at(_UER_Actors, j);

            if (actor->parent != NULL)
            {
                for (int k = 0; k < vector_size(actor->parent->children); k++)
                {
                    Actor *child = vector_get(actor->parent->children, k);

                    if (child->id == actor->id)
                    {
                        vector_remove_at(actor->parent->children, k);
                    }
                }
            }

            break;
        }

        vector_remove_at(_UER_ActorsPendingRemoval, i);

        free(actorToRemove);
    }
}

void lock_pairs(void)
{
    for (int x = 0; x < pair_count; x++)
    {
        locked[pairs[x].winner][pairs[x].loser] = true;
        //check if cycle was created
        for (int i = 0; i < candidate_count; i++)
        {
            for (int j = 0; j < candidate_count; j++)
            {
                if (j == i)
                {
                    continue;
                }
                else if (locked[j][i])
                {
                    break;
                }
                //if there is still a source, keep lock pairs
                else if (j == candidate_count - 1)
                {
                    i = MAX + 1;
                }
            }
            // if there is no source left, unlock the last pair
            if (i == candidate_count - 1)
            {
                locked[pairs[x].winner][pairs[x].loser] = false;
            }
        }
    }
    return;
}
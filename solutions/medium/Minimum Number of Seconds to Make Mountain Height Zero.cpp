// Title: Minimum Number of Seconds to Make Mountain Height Zero
            // Difficulty: Medium
            // Language: C++
            // Link: https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/

            ll tot = 0;
            for (int i = 0; i < times.size() && tot < height; i++)
                tot += (ll)(sqrt((double)mid / times[i] * 2 + 0.25) - 0.5);
            if (tot >= height)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};

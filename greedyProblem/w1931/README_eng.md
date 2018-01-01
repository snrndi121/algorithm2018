# problem
 - There is a meeting room and we should make scheduled menu. Each meetinghas start time and end time, '(T_start, T_end)'. Thus, those schedules should not overlap and find the maximum meetings.

 - A meeting can not be stopped while proceeding. Besides, it can be started if the meeeing were over.

 - It is possible to be same the start with the end. In this case, you can consider it it over as soone as you start. 

# condition
 - the number of meetings(n) : 1<= n <= 100,000
 - the range of time : 2^31-1 && integer

# input
>> 11
>> 1 4
>> 3 5
>> 0 6
>> 5 7
>> 3 8
>> 5 9
>> 6 10
>> 8 11
>> 8 12
>> 2 13
>> 12 14

# output
4

# hint
- greedy searching

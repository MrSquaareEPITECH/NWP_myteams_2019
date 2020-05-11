# my_teams DATABASE
Version 1.0

## Teams
```xml
<teams>
<team id="%TEAM_UUID%" name="%TEAM_NAME%" description="%TEAM_DESCRIPTION">
<channels>
<channel id="%CHANNEL_UUID%" name="%CHANNEL_NAME%" description="%CHANNEL_DESCRIPTION%">
<threads>
<thread id="%THREAD_UUID%" timestamp="%THREAD_TIMESTAMP%" name="%THREAD_NAME%" description="%THREAD_DESCRIPTION%">
"%TIMESTAMP%" "%BODY%"
...
"%TIMESTAMP%" "%BODY%"
</thread>
</threads>
</channel>
</channels>
<subscribers>
"%USER_NAME%"
...
"%USER_NAME%"
</subscribers>
</team>
</teams>
```

## Users

```xml
<users>
<user id="%USER_NAME%">
<privates>
<private id="%USER_NAME">
"%TIMESTAMP%" "%BODY%"
...
"%TIMESTAMP%" "%BODY%"
</private>
</privates>
</user>
</users>
```

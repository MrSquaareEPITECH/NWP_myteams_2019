# my_teams DATABASE
Version 1.1

## Teams
```xml
<teams>
    <team id="%TEAM_UUID%" name="%TEAM_NAME%" description="%TEAM_DESCRIPTION">
        <channels>
            <channel id="%CHANNEL_UUID%" name="%CHANNEL_NAME%" description="%CHANNEL_DESCRIPTION%">
                <threads>
                    <thread id="%THREAD_UUID%" timestamp="%THREAD_TIMESTAMP%" name="%THREAD_NAME%" description="%THREAD_DESCRIPTION%">
                        <comment timestamp="%TIMESTAMP%">"%BODY%"</comment>
                        <!-- ... -->
                        <comment timestamp="%TIMESTAMP%">"%BODY%"</comment>
                    </thread>
                </threads>
            </channel>
        </channels>
        <subscribers>
            <subscriber>"%USER_ID%"</subscriber>
            <!-- ... -->
            <subscriber>"%USER_ID%"</subscriber>
        </subscribers>
    </team>
</teams>
```

## Users

```xml
<users>
    <user id="%USER_ID%" name="%USER_NAME%">
        <privates>
            <private id="%USER_ID">
                <message timestamp="%TIMESTAMP%">"%BODY%"</message>
                <!-- ... -->
                <message timestamp="%TIMESTAMP%">"%BODY%"</message>
            </private>
        </privates>
    </user>
</users>
```

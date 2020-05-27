# my_teams DATABASE
Version 2.0

## Teams
```xml
<teams>
    <team id="%TEAM_UUID%" name="%TEAM_NAME%" description="%TEAM_DESCRIPTION">
        <channels>
            <channel id="%CHANNEL_UUID%" name="%CHANNEL_NAME%" description="%CHANNEL_DESCRIPTION%">
                <threads>
                    <thread id="%THREAD_UUID%" timestamp="%THREAD_TIMESTAMP%" name="%THREAD_NAME%" description="%THREAD_DESCRIPTION%">
                        <comments>
                            <comment timestamp="%TIMESTAMP%">"%BODY%"</comment>
                            <!-- ... -->
                            <comment timestamp="%TIMESTAMP%">"%BODY%"</comment>
                        </comments>
                    </thread>
                </threads>
            </channel>
        </channels>
        <subscribers>
            <subscriber id="%USER_ID%"/>
            <!-- ... -->
            <subscriber id="%USER_ID%"/>
        </subscribers>
    </team>
</teams>
```

## Exchanges

```xml
<exchanges>
    <exchange id="%EXCHANGE_ID%">
        <messages>
            <message timestamp="%TIMESTAMP%" user="%USER_ID%">"%BODY%"</message>
            <!-- ... -->
            <message timestamp="%TIMESTAMP%" user="%USER_ID%">"%BODY%"</message>
        </messages>
    </exchange>
</exchanges>
```

## Users

```xml
<users>
    <user id="%USER_ID%" name="%USER_NAME%">
        <privates>
            <private uuid="%USER_ID" exchange="%EXCHANGE_ID%"/>
        </privates>
    </user>
</users>
```

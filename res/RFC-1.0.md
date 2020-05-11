# my_teams RFC
Version: 1.0

#### Note
- Every line ends with a line break
- Client knows his current use

## COMMANDS

### Global

- Help
    - `HELP`

### Channel
- Create
    - `CHANNEL CREATE "<team_uuid>" "<name>" "<description>"`
- Exists
    - `CHANNEL EXISTS "<team_uuid>" "<uuid>"`
- Information
    - `CHANNEL INFO "<team_uuid>" "<uuid>"`
- List
    - `CHANNEL LIST "<team_uuid>"`

### Comment
- Create
    - `COMMENT CREATE "<team_uuid>" "<channel_uuid>" "<thread_uuid>" "<body>"`
- List
    - `COMMENT LIST "<team_uuid>" "<channel_uuid>" "<thread_uuid>"`

### Private
- Exists
    - `PRIVATE EXISTS "<user_uuid>"`
- List
    - `PRIVATE LIST "<user_uuid>"`
- Send
    - `PRIVATE SEND "<user_uuid>" "<message>"`

### Team
- Create
    - `TEAM CREATE "<name>" "<description>"`
- Exists
    - `TEAM EXISTS "<uuid>"`
- Information
    - `TEAM INFO "<uuid>"`
- List
    - `TEAM LIST`
- Subscribers
    - `TEAM SUBSCRIBERS "<uuid>"`

### Thread
- Create
    - `THREAD CREATE "<team_uuid>" "<channel_uuid>" "<name>" "<description>"`
- Exists
    - `TEAM EXISTS "<team_uuid>" "<channel_uuid>" "<uuid>"`
- Information
    - `THREAD INFO "<team_uuid>" "<channel_uuid>" "<uuid>"`
- List
    - `THREAD LIST "<team_uuid>" "<channel_uuid>"`

### User
- Exists
    - `USER EXISTS "<uuid>"`
- Information
    - `USER INFO "<uuid>"`
- List
    - `USER LIST [<filter>]`
        - `<filter>`: `ALL` | `CONNECTED` | `DISCONNECTED`
- Login
    - `USER LOGIN "<username>"`
- Logout
    - `USER LOGOUT`
- Subscribe
    - `USER SUBSCRIBE "<team_uuid>"`
- Subscriptions
    - `USER SUBSCRIPTIONS`
- Unsubscribe
    - `USER UNSUBSCRIBE "<team_uuid>"`

## RESPONSES

### Channel
- Create
    - `CHANNEL CREATE OK ["<message>"]`: Success
    - `CHANNEL CREATE KO ["<message>"]`: Error
- Exists
    - `CHANNEL EXISTS OK ["<message>"]`: Success
    - `CHANNEL EXISTS KO ["<message>"]`: Error
- Information
    - Success
    ```text
    CHANNEL INFO OK ["<message>"]
    CHANNEL INFO "<uuid>" "<name>" "<description>"
    ```
    - `CHANNEL INFO KO ["<message>"]`: Error
- List
    - Success
    ```text
    CHANNEL LIST OK ["<message>"]
    CHANNEL LIST START
    "<uuid>" "<name>" "<description>"
    ...
    "<uuid>" "<name>" "<description>"
    CHANNEL LIST END
    ```
    - `CHANNEL LIST KO ["<message>"]`: Error

### Comment
- Create
    - `COMMENT CREATE OK ["<message>"]`: Success
    - `COMMENT CREATE KO ["<message>"]`: Error
- List
    - Success
    ```text
    COMMENT LIST OK ["<message>"]
    COMMENT LIST START
    "<timestamp>" "<body>"
    ...
    "<timestamp>" "<body>"
    COMMENT LIST END
    ```
    - `COMMENT LIST KO ["<message>"]`: Error

### Private
- Exists
    - `PRIVATE EXISTS OK ["<message>"]`: Success
    - `PRIVATE EXISTS KO ["<message>"]`: Error
- List
    - Success
    ```text
    PRIVATE LIST OK ["<message>"]
    PRIVATE LIST START
    "<timestamp>" "<body>"
    ...
    "<timestamp>" "<body>"
    PRIVATE LIST END
    ```
    - `PRIVATE LIST KO ["<message>"]`: Error
- Send
    - `PRIVATE SEND OK ["<message>"]`: Success
    - `PRIVATE SEND KO ["<message>"]`: Error

### Team
- Create
    - `TEAM CREATE OK ["<message>"]`: Success
    - `TEAM CREATE KO ["<message>"]`: Error
- Exists
    - `TEAM EXISTS OK ["<message>"]`: Success
    - `TEAM EXISTS KO ["<message>"]`: Error
- Information
    - Success
    ```text
    TEAM INFO OK ["<message>"]
    TEAM INFO "<name>" "<description>" "<uuid>"
    ```
    - `TEAM INFO KO ["<message>"]`: Error
- List
    - Success
    ```text
    TEAM LIST OK ["<message>"]
    TEAM LIST START
    "<name>" "<description>" "<uuid>"
    ...
    "<name>" "<description>" "<uuid>"
    TEAM LIST END
    ```
    - `TEAM LIST KO ["<message>"]`: Error
- Subscribers
    - Success
    ```text
    TEAM SUBSCRIBERS OK ["<message>"]
    TEAM SUBSCRIBERS START
    "<name>"
    ...
    "<name>"
    TEAM SUBSCRIBERS END
    ```
    - `TEAM SUBSCRIBERS KO ["<message>"]`: Error

### Thread
- Create
    - `THREAD CREATE OK ["<message>"]`: Success
    - `THREAD CREATE KO ["<message>"]`: Error
- Exists
    - `THREAD EXISTS OK ["<message>"]`: Success
    - `THREAD EXISTS KO ["<message>"]`: Error
- Information
    - Success
    ```text
    THREAD INFO OK ["<message>"]
    THREAD INFO "<uuid>" "<timestamp>" "<name>" "<description>"
    ```
    - `TEAM INFO KO ["<message>"]`: Error
- List
    - Success
    ```text
    THREAD LIST OK ["<message>"]
    THREAD LIST START
    "<uuid>" "<timestamp>" "<name>" "<description>"
    ...
    "<uuid>" "<timestamp>" "<name>" "<description>"
    THREAD LIST END
    ```
    - `THREAD LIST KO ["<message>"]`: Error

### User
- Exists
    - `USER EXISTS OK ["<message>"]`: Success
    - `USER EXISTS KO ["<message>"]`: Error
- List
    - Success
    ```text
    USER LIST OK ["<message>"]
    USER LIST START
    "<name>" "<status>"
    ...
    "<name>" "<status>"
    USER LIST END
    ```
    - `USER LIST KO ["<message>"]`: Error
- Login
    - `USER LOGIN OK ["<message>"]`: Success
    - `USER LOGIN KO ["<message>"]`: Error
- Logout
    - `USER LOGOUT OK ["<message>"]`: Success
    - `USER LOGOUT KO ["<message>"]`: Error
- Subscribe
    - `USER SUBSCRIBE OK ["<message>"]`: Success
    - `USER SUBSCRIBE KO ["<message>"]`: Error
- Subscriptions
    - Success
    ```text
    USER SUBSCRIPTIONS OK ["<message>"]
    USER SUBSCRIPTIONS START
    "<uuid>" "<name>" "<description>"
    ...
    "<uuid>" "<name>" "<description>"
    USER SUBSCRIPTIONS END
    ```
    - `USER SUBSCRIPTIONS KO ["<message>"]`: Error
- Unsubscribe
    - `USER UNSUBSCRIBE OK ["<message>"]`: Success
    - `USER UNSUBSCRIBE KO ["<message>"]`: Error

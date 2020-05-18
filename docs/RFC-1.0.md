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
- List
    - `COMMENT LIST "<team_uuid>" "<channel_uuid>" "<thread_uuid>"`
- Create
    - `COMMENT SEND "<team_uuid>" "<channel_uuid>" "<thread_uuid>" "<body>"`

### Message
- Exists
    - `MESSAGE EXISTS "<user_uuid>"`
- List
    - `MESSAGE LIST "<user_uuid>"`
- Send
    - `MESSAGE SEND "<user_uuid>" "<message>"`

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
    - `THREAD CREATE "<team_uuid>" "<channel_uuid>" "<name>" "<body>"`
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
    - Success
    ```text
    CHANNEL CREATE OK ["<message>"]
    "<uuid>" "<name>" "<description>"
    ```
    - `CHANNEL CREATE KO ["<message>"]`: Error
- Exists
    - `CHANNEL EXISTS OK ["<message>"]`: Success
    - `CHANNEL EXISTS KO ["<message>"]`: Error
- Information
    - Success
    ```text
    CHANNEL INFO OK ["<message>"]
    "<uuid>" "<name>" "<description>"
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
- Send
    - `COMMENT SEND OK ["<message>"]`: Success
    - `COMMENT SEND KO ["<message>"]`: Error

### Message
- Exists
    - `MESSAGE EXISTS OK ["<message>"]`: Success
    - `MESSAGE EXISTS KO ["<message>"]`: Error
- List
    - Success
    ```text
    MESSAGE LIST OK ["<message>"]
    MESSAGE LIST START
    "<timestamp>" "<body>"
    ...
    "<timestamp>" "<body>"
    MESSAGE LIST END
    ```
    - `MESSAGE LIST KO ["<message>"]`: Error
- Send
    - `MESSAGE SEND OK ["<message>"]`: Success
    - `MESSAGE SEND KO ["<message>"]`: Error

### Team
- Create
    - Success
    ```text
    TEAM CREATE OK ["<message>"]
    "<uuid>" "<name>" "<description>"
    ```
    - `TEAM CREATE KO ["<message>"]`: Error
- Exists
    - `TEAM EXISTS OK ["<message>"]`: Success
    - `TEAM EXISTS KO ["<message>"]`: Error
- Information
    - Success
    ```text
    TEAM INFO OK ["<message>"]
    "<uuid>" "<name>" "<description>"
    ```
    - `TEAM INFO KO ["<message>"]`: Error
- List
    - Success
    ```text
    TEAM LIST OK ["<message>"]
    TEAM LIST START
    "<uuid>" "<name>" "<description>"
    ...
    "<uuid>" "<name>" "<description>"
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
    - Success
    ```text
    THREAD CREATE OK ["<message>"]
    "<uuid>" "<timestamp>" "<name>" "<body>"
    ```
    - `THREAD CREATE KO ["<message>"]`: Error
- Exists
    - `THREAD EXISTS OK ["<message>"]`: Success
    - `THREAD EXISTS KO ["<message>"]`: Error
- Information
    - Success
    ```text
    THREAD INFO OK ["<message>"]
    "<uuid>" "<timestamp>" "<name>" "<body>"
    ```
    - `TEAM INFO KO ["<message>"]`: Error
- List
    - Success
    ```text
    THREAD LIST OK ["<message>"]
    THREAD LIST START
    "<uuid>" "<timestamp>" "<name>" "<body>"
    ...
    "<uuid>" "<timestamp>" "<name>" "<body>"
    THREAD LIST END
    ```
    - `THREAD LIST KO ["<message>"]`: Error

### User
- Exists
    - `USER EXISTS OK ["<message>"]`: Success
    - `USER EXISTS KO ["<message>"]`: Error
- Info
    - Success
    ```text
    USER INFO OK ["<message>"]
    "<uuid>" "<name>"
    ```
    - `USER INFO KO ["<message>"]`: Error
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
    - Success
    ```text
    USER SUBSCRIBE OK ["<message>"]
    "<uuid>" "<team_uuid>"
    ```
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
    - Success
    ```text
    USER UNSUBSCRIBE OK ["<message>"]
    "<uuid>" "<team_uuid>"
    ```
    - `USER UNSUBSCRIBE KO ["<message>"]`: Error

## EVENTS

### Channel
- Create
    - `CHANNEL CREATED "<uuid>" "<name>" "<description>"`

### Comment
- Send
    - `COMMENT SENT "<user_uuid>" "<team_uuid>" "<uuid>" "<body>"`

### Message
- Send
    - `MESSAGE SENT "<user_uuid>" "<body>"`

### Team
- Create
    - `TEAM CREATED "<uuid>" "<name>" "<body>"`

### Team
- Create
    - `THREAD CREATED "<user_uuid>" "<uuid>" "<timestamp>" "<name>" "<description>"`

### User
- Login
    - `USER LOGGEDIN "<uuid>" "<name>"`
- Logout
    - `USER LOGGEDOUT "<uuid>" "<name>"`

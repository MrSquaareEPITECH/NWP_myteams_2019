# my_teams RFC
Version: 2.0

#### Note
- Every line ends with a line break
- Server knows the client's current use

## COMMANDS

### Global

- Help
    - `/help`

### Channel
- Create (1)
    - `/create "<name>" "<description>"`
- Information (2)
    - `/info`
- List (1)
    - `/list`
- Use
    - `/use "<team_uuid>" "<uuid>"`

1) Depends on: `/use "<team_uuid>"`
2) Depends on: `/use "<team_uuid>" "<uuid>"`

### Comment
- Create (1)
    - `/create "<body>"`
- List (1)
    - `/list`

1) Depends on: `/use "<team_uuid>" "<channel_uuid> "<thread_uuid>`

### Message
- List (1)
    - `/messages "<user_uuid>"`
- Send
    - `/send "<user_uuid>" "<body>"`

### Team
- Create (1)
    - `/create "<name>" "<description>"`
- Information (2)
    - `/info`
- List (1)
    - `/list`
- Use
    - `/use "<team_uuid>"`

1) Depends on: `/use`
2) Depends on: `/use "<team_uuid>"`

### Thread
- Create (1)
    - `/create "<name>" "<description>"`
- Information (2)
    - `/info`
- List (1)
    - `/list`
- Use
    - `/use "<team_uuid>" "<channel_uuid>" "<thread_uuid>"`

1) Depends on: `/use "<team_uuid>" "<channel_uuid>"`
2) Depends on: `/use "<team_uuid>" "<channel_uuid>" "<thread_uuid>"`

### User
- All
    - `/users`
- Information (1)
    - `/info`
- Information (user)
    - `/user "<uuid>"`
- Login
    - `/login "<username>"`
- Logout
    - `/logout`
- Subscribe
    - `/subscribe "<team_uuid>"`
- Subscriptions
    - `/subscribed`
- Unsubscribe
    - `/unsubscribe "<team_uuid>"`

1) Depends on: `/use`

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
    - `TEAM CREATED "<uuid>" "<name>" "<description>"`

### Team
- Create
    - `THREAD CREATED "<user_uuid>" "<uuid>" "<timestamp>" "<name>" "<description>"`

### User
- Login
    - `USER LOGGEDIN "<uuid>" "<name>"`
- Logout
    - `USER LOGGEDIN "<uuid>" "<name>"`

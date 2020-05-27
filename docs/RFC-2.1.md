# my_teams RFC
Version: 2.1

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

1) Depends on: `/use "<team_uuid>" "<channel_uuid> "<thread_uuid>"`

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

### Generic codes
- 0: OK
- 100: Error
- 101: Not logged
- 102: Missing arguments
- 103: Wrong argument
- 104: Doesn't exist

### Global
- Create
    - `GLOBAL CREATE KO ["<message>"]`: Error
- Help
    - Success
    ```text
    GLOBAL HELP OK ["<message>"]
    GLOBAL HELP START
    "<name>" "<help>"
    ...
    "<name>" "<help>"
    GLOBAL HELP END
    ```
    - `GLOBAL HELP KO ["<message>"]`: Error
- Info
    - `GLOBAL INFO KO ["<message>"]`: Error
- List
    - `GLOBAL LIST KO ["<message>"]`: Error
- List
    - `GLOBAL SUBSCRIBED KO ["<message>"]`: Error

### Channel
- Create
    - Success
    ```text
    CHANNEL CREATE OK ["<message>"]
    "<uuid>" "<name>" "<description>"
    ```
    - `CHANNEL CREATE KO ["<message>"]`: Error
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
    "<thread_uuid>" "<user_uuid>" "<timestamp>" "<body>"
    ...
    "<thread_uuid>" "<user_uuid>" "<timestamp>" "<body>"
    COMMENT LIST END
    ```
    - `COMMENT LIST KO ["<message>"]`: Error
- Send
    - Success
    ```text
    COMMENT SEND OK ["<message>"]
    "<thread_uuid>" "<user_uuid>" "<timestamp>" "<body>"
    ```
    - `COMMENT SEND KO ["<message>"]`: Error

### Message
- List
    - Success
    ```text
    MESSAGE LIST OK ["<message>"]
    MESSAGE LIST START
    "<user_uuid>" "<timestamp>" "<body>"
    ...
    "<user_uuid>" "<timestamp>" "<body>"
    MESSAGE LIST END
    ```
    - `MESSAGE LIST KO ["<message>"]`: Error
- Send
    - Success
    ```text
    MESSAGE SEND OK ["<message>"]
    "<user_uuid>" "<timestamp>" "<body>"
    ```
    - `MESSAGE SEND KO ["<message>"]`: Error

### Team
- Create
    - Success
    ```text
    TEAM CREATE OK ["<message>"]
    "<uuid>" "<name>" "<description>"
    ```
    - `TEAM CREATE KO ["<message>"]`: Error
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
    "<uuid>"
    ...
    "<uuid>"
    TEAM SUBSCRIBERS END
    ```
    - `TEAM SUBSCRIBERS KO ["<message>"]`: Error

### Thread
- Create
    - Success
    ```text
    THREAD CREATE OK ["<message>"]
    "<uuid>" "<user_uuid>" "<timestamp>" "<name>" "<body>"
    ```
    - `THREAD CREATE KO ["<message>"]`: Error
- Information
    - Success
    ```text
    THREAD INFO OK ["<message>"]
    "<uuid>" "<user_uuid>" "<timestamp>" "<name>" "<body>"
    ```
    - `TEAM INFO KO ["<message>"]`: Error
- List
    - Success
    ```text
    THREAD LIST OK ["<message>"]
    THREAD LIST START
    "<uuid>" "<user_uuid>" "<timestamp>" "<name>" "<body>"
    ...
    "<uuid>" "<user_uuid>" "<timestamp>" "<name>" "<body>"
    THREAD LIST END
    ```
    - `THREAD LIST KO ["<message>"]`: Error

### User
- Info
    - Success
    ```text
    USER INFO OK ["<message>"]
    "<uuid>" "<name>" "status"
    ```
    - `USER INFO KO ["<message>"]`: Error
- List
    - Success
    ```text
    USER LIST OK ["<message>"]
    USER LIST START
    "<uuid>" "<name>" "status"
    ...
    "<uuid>" "<name>" "status"
    USER LIST END
    ```
    - `USER LIST KO ["<message>"]`: Error
- Login
    - Success
    ```text
    USER LOGIN OK ["<message>"]
    "<uuid>" "<name>" "status"
    ```
    - `USER LOGIN KO ["<message>"]`: Error
- Logout
    ```text
    USER LOGOUT OK ["<message>"]
    "<uuid>" "<name>" "status"
    ```
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
    "<uuid>" "<team_uuid>"
    ...
    "<uuid>" "<team_uuid>"
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
    ```text
    CHANNEL CREATED
    "<uuid>" "<name>" "<description>"
    ```

### Comment
- Send
    ```text
    COMMENT SENT
    "<team_uuid>" "<thread_uuid>" "<user_uuid>" "<timestamp>" "<body>"
    ```
    - `COMMENT SENT "<user_uuid>" "<team_uuid>" "<uuid>" "<body>"`

### Message
- Send
    ```text
    MESSAGE SENT
    "<user_uuid>" "<timestamp>" "<body>"
    ```

### Team
- Create
    ```text
    TEAM CREATED
    "<uuid>" "<name>" "<description>"
    ```

### Team
- Create
    ```text
    THREAD CREATED
    "<uuid>" "<user_uuid>" "<timestamp>" "<name>" "<description>"
    ```

### User
- Login
    ```text
    USER LOGGEDIN
    "<uuid>" "<name>" "<status>"
    ```
- Logout
    ```text
    USER LOGGEDOUT
    "<uuid>" "<name>" "<status>"
    ```

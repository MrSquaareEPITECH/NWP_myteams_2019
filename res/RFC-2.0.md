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

### Private
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



# API
Create an instance of the class
for example, create the object 'vpw'.

`j1850 vpw;`
### Initialization

#### `void j1850::init(int RX_PIN, int TX_PIN, bool debug = false)`
- **RX_PIN**: Pin used for receiving signals.
- **TX_PIN**: Pin used for transmitting signals.
- **debug**: Enables or disables debugging mode (default: `false`).

**Example:**
```cpp
vpw.init(10, 11, true);
```

### Debugging Mode
Debugging mode allows you to:
- View incoming messages.
- View outgoing messages.
- Monitor status codes.


To change modes, send a number via the Serial Console:
- **1** (default): Display both incoming and outgoing messages.
- **2**: Display status codes.
- **3**: Display only outgoing messages.
- **4**: Display only incoming messages.
- **5**: Run tests.

### Receiving Messages

#### `bool j1850::accept(byte *msg_buf, bool check_crc = false)`
- **msg_buf**: Buffer to store the received message.
- **check_crc**: Enables CRC validation (default: `false`).

**Return Value:**
- `true`: Message received successfully.
- `false`: Message reception failed.

**Example:**
Before receiving messages, create a buffer. The J1850 protocol supports messages up to **12 bytes**:
```cpp
byte rx_buf[12];
```
To receive a message:
```cpp
if (vpw.accept(rx_buf)) {
    // Process the received message
}
```
The property **`rx_nbyte`** will contain the number of bytes received.

### Sending Messages

#### Method 1: `bool j1850::send(byte *tx_buf, int nbytes)`
- **tx_buf**: Buffer containing the message to send.
- **nbytes**: Number of bytes to send (maximum: 12).

**Return Value:**
- `true`: Message sent successfully.
- `false`: Message sending failed.

**Example:**
```cpp
byte tx_buf[] = {0x00, 0x01, 0x03};
if (vpw.send(tx_buf, 3)) {
    // Message sent successfully
}
```

#### Method 2: `bool j1850::easy_send(int size, ...)`
- **size**: Number of bytes to send.
- Variable arguments: The bytes to send.

**Return Value:**
- `true`: Message sent successfully.
- `false`: Message sending failed.

**Example:**
```cpp
if (vpw.easy_send(3, 0x00, 0x01, 0x03)) {
    // Message sent successfully
}
```
In both methods, the CRC will be automatically calculated and appended to the message. The number of bytes sent is stored in the **`tx_nbyte`** property.

### Status Codes
The **`message`** property holds the last event code:
- **1**: `MESSAGE_SEND_OK` (Message sent successfully)
- **2**: `MESSAGE_ACCEPT_OK` (Message received successfully)
- **3**: `ERROR_MESSAGE_TOO_LONG` (Message exceeds maximum length)
- **4**: `ERROR_NO_RESPONSE_WITHIN_100US` (No response detected within 100 microseconds)
- **5**: `ERROR_ON_SOF_TIMEOUT` (Start-of-frame timeout)
- **6**: `ERROR_SYMBOL_WAS_NOT_SOF` (Invalid start-of-frame symbol)
- **7**: `ERROR_SYMBOL_WAS_NOT_SHORT` (Invalid short symbol detected)
- **8**: `ERROR_ACCEPT_CRC` (CRC validation failed)


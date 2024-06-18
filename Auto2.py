# Importing necessary libraries
import hmac
import hashlib

# Function to calculate HMAC-SHA256
def hmac_sha256(key, msg):
    return hmac.new(key.encode(), msg.encode(), hashlib.sha256).hexdigest()

# Function to convert bytes to number
def bytes_to_number(bytes_str):
    byte_values = [int(byte_str, 16) for byte_str in bytes_str]
    number = sum(byte_values[i] / (256 ** (i + 1)) for i in range(len(byte_values)))
    return number

# Function to decode coordinates
def decode_coordinates(values):
    decoded_coordinates = []
    for i in range(0, len(values), 4):
        value = values[i:i+4]
        number = bytes_to_number(value)
        coordinate = round(number * 25) % 25
        x = (coordinate % 5) + 1
        y = 5 - (coordinate // 5)
        decoded_coordinates.append((x, y))
    return decoded_coordinates

# Function to determine mine locations
def determine_mine_locations(server_seed, client_seed, total_bets):
    mine_values = []
    for i in range(4):  # Ensure we always decode 4 locations
        hmac_key = hmac_sha256(server_seed, f"{client_seed}::{i}")
        bytes_str = hmac_sha256(hmac_key, "")
        mine_values.append(bytes_str)

    mine_coordinates = decode_coordinates(mine_values)
    return mine_coordinates

# Example usage
server_seed = "202b08b453cdc5dd2d8ab94167018241bf1e4d55b8ae89d59d59f6c01fac8229"
client_seed = "52JXO7WE7Y"
total_bets = 2

mine_locations = determine_mine_locations(server_seed, client_seed, total_bets)
print("Mine Locations:")
for i, location in enumerate(mine_locations, start=1):
    print(f"Mine {i}: {location}")

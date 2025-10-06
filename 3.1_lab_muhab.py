class Airport:
    def __init__(self, name: str, price: float, seats: int, sold: int):
        self.set_name(name)
        self.set_price(price)
        self.set_place(seats)
        self.set_ticket(sold)

    def set_name(self, n: str):
        self.name = n

    def set_price(self, p: float):
        while p > 1_000_000 or p <= 0:
            p = float(input("Ошибка: цена должна быть > 0 и < 1000000. Введите снова: "))
        self.price = p

    def set_place(self, seats: int):
        while seats <= 0 or seats > 500:
            seats = int(input("Ошибка: количество мест должно быть от 1 до 500. Введите снова: "))
        self.place = seats

    def set_ticket(self, sold: int):
        while 0 > sold > self.place:
            if sold < 0:
                sold = int(input("Ошибка: количество проданных билетов не может быть отрицательным. Введите снова: "))
            else:
                sold = int(input(f"Ошибка: билетов не может быть больше, чем мест ({self.place}). Введите снова: "))
        self.ticket = sold

    def get_name(self) -> str:
        return self.name

    def get_price(self) -> float:
        return self.price

    def get_place(self) -> int:
        return self.place

    def get_ticket(self) -> int:
        return self.ticket

    def all_ticket_price(self) -> float:
        return self.ticket * self.price


if __name__ == "__main__":
    name = input("Введите название аэропорта: ")
    price = float(input("Введите цену билета: "))
    seats = int(input("Введите количество мест (1-500): "))
    sold = int(input("Введите количество проданных билетов: "))

    tablo = Airport(name, price, seats, sold)

    print("\n--- Итоговые данные ---")
    print(f"Название: {tablo.get_name()}")
    print(f"Цена: {tablo.get_price()} руб.")
    print(f"Всего мест: {tablo.get_place()}")
    print(f"Продано билетов: {tablo.get_ticket()}")
    print(f"Выручка: {tablo.all_ticket_price()} руб.")
